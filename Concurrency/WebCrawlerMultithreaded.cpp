class Solution {
    public:
    string hostname;
    queue<string> q;
    set<string> visitedUrls;
    int working = 0; // number of working threads
    bool done;
    mutex m;
    condition_variable cv;
    
    string getHostName(string url){
        // http://leetcode.com/problems
        return url.substr(0, url.find("/", 7));
    }
    
    
    void startWorker(HtmlParser* parser){
        while(true){
            unique_lock<mutex> lk(m);
            while(q.empty() && !done){
                cv.wait(lk);
            }
            
            if(done){
                return;
            }
            ++working;
            string url = q.front();
            q.pop();
            lk.unlock();
            
            vector<string> urls = parser->getUrls(url);
            
            lk.lock();
            for(string curUrl : urls){
                auto it = visitedUrls.find(curUrl);
                if(it == visitedUrls.end() && getHostName(curUrl) == hostname){
                    q.push(curUrl);
                    visitedUrls.insert(curUrl);
                }
            }
            --working;
            if(q.empty() && working == 0){
                done = true;
            }
            cv.notify_all();            
        }
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        done = false;
        hostname = getHostName(startUrl);
        int threadNum = thread::hardware_concurrency();
        vector<thread> workers;
        
        visitedUrls.insert(startUrl);
        q.push(startUrl);
        
        for(int i = 0; i < threadNum; ++i){
            workers.push_back(std::thread(&Solution::startWorker, this, &htmlParser));
        }
        for(auto &it : workers){
            it.join();
        }
        return vector<string>(visitedUrls.begin(), visitedUrls.end());
        
        
    }  
};
