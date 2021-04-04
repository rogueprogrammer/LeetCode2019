/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
/*

1. Assume we have 10,000 nodes and 1 billion URLs to crawl. We will deploy the same software onto each node. The software can know about all the nodes. We have to minimize communication between machines and make sure each node does equal amount of work. How would your web crawler design change?

   - queue needsto be a distributed and concurrent queue such as kafka message queue
   - visited set can be a bloom filter. Bloom filter is a probabilistic data structure that can
   tell with hundred percent confidence if an element is not in a set. It is only 90 percent sure that an element is in the set. 
   Bloom filter is a bit set with multiple hash functions. Each hash function will be used to set a bit at the corresponding index. 
   
   Example:
      if url1 has hash values for 1, 3, 9 for hash functions 1-3, then we set the bits at indices 1, 3, 9 to be 1. Then when we want to search if a certain url was visited, we know for sure if it wasn't visited by checking if it was in the set. For example, 40 million elements in a bloom filter bit set is
      40 million bits, which is 5 MB. So if multiple machines want to query it, even IO would be very less. One node can be maintianing and sending the bloom filter to all other machines periodically upon updates to it. To avoid single point of failure, the node maintaining the bloom filter can be replicated across 2 other worker nodes. 
   Each node can be responsible for taking care of urls that hash to certain range. 

2. What if one node fails or does not work?
Each node sends its heart beats to other nodes or to a centralized node such as Zookeeper. If node doesn't send its heart beat to Zookeeper within certain timeframe, then we know it's done.  

3. How do you know when the crawler is done?
Crawler is done once queue is empty and number of working nodes is also 0 (each node has 0 urls to process).

*/



class Solution {
public:
    
bool shareHostName(string url1, string url2) {
		 url1 = url1.substr(7, url1.find('/', 7) - 7);
		 url2 = url2.substr(7, url2.find('/', 7) - 7);
		 return url1 == url2;
	 }
	 
/*google.com
      google.com/photos
      yahoo.com
          yahoo.com/videos
          yahoo.com/mail
      google.com/mail
           google.com/videos
           cnn.com
           xbox.com
           msn.com
    Traversal can be DFS or BFS solution
*/
     mutex m;
     condition_variable cv;
     int numThreadsWorking = 0;
     queue<string> q; //q is a shared resource
     set<string> visited; //shared resource
    
	 void startCrawling(HtmlParser htmlParser) {

         
         while(1){
             unique_lock<mutex> lk(m); //one thread can acquire this function at a time with lk
             
             
             while(q.empty() && numThreadsWorking > 0){
                 cv.wait(lk);
             }
             
             //  if no tasks to work on and no other threads are working, then we are done.
             if(q.empty() && numThreadsWorking == 0){
                 break;
             }
             
             ++numThreadsWorking;
             string curUrl = q.front();
             q.pop();
             auto it = visited.find(curUrl);
             if(it == visited.end()){
                 visited.insert(curUrl);
                 lk.unlock();
                 
                 // since getUrls can take a lot of time, release the lock.
                 vector<string> neighbors = htmlParser.getUrls(curUrl);
                 
                 lk.lock();
                 for(string neighbor : neighbors){
                     if(shareHostName(neighbor, curUrl)){
                         q.push(neighbor);
                     }
                 }
             }
             
             --numThreadsWorking;
             cv.notify_all();
             lk.unlock();
         }
     }
         
         /* SINGLE THREADED WEB CRAWLER:
         queue<string> q;
         set<string> visited;
         q.push(startUrl);
         while(!q.empty()){
             
             string curUrl = q.front();
             q.pop();
             auto it = visited.find(curUrl);
             if(it == visited.end()){
                 visited.insert(curUrl);
                 vector<string> neighbors = htmlParser.getUrls(curUrl);
                 for(string neighbor : neighbors){
                     if(shareHostName(neighbor, curUrl)){
                         q.push(neighbor);
                     }
                 }
             }
             
         }
         return vector<string>(visited.begin(), visited.end());*/

    vector<string> crawl(string startUrl, HtmlParser htmlParser){
       
        q.push(startUrl);
        
        vector<thread> threadPool;
        int numThreads = thread::hardware_concurrency();
        
        for(int i = 0; i < numThreads; ++i){
            threadPool.push_back(std::thread(&Solution::startCrawling, this, htmlParser));
        }
        for(auto& it : threadPool){
            it.join();
        }
        return vector<string>(visited.begin(), visited.end());        
    }

};
