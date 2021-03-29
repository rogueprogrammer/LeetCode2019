   set<string> visited;
	 queue<string> q;
	 mutex m;
   condition_variable cv;
/*
why commented code doesn't work? how to make cv wait and signal?
max number of threads to use? Why number of threads is equal to hardware_concurrency (number of cores)? Why can't it be more, solution seems to fail if I use more than
hardware_concurrency. Confirm what is the max number of threads that can run?
*/


bool shareHostName(string url1, string url2) {
		 url1 = url1.substr(7, url1.find('/', 7) - 7);
		 url2 = url2.substr(7, url2.find('/', 7) - 7);
		 return url1 == url2;
	 }
	 

	 void startCrawling(HtmlParser* htmlParser) {
		 unique_lock<mutex> lk(m);
     //while(q.empty()){
      //cv.wait(); 
     //}
		 while (!q.empty()) {
			 string cur = q.front(); q.pop();
			 auto it = visited.find(cur);
			 if (it == visited.end()) {
				 visited.insert(cur);
				 lk.unlock();
				 vector<string> neighbors = htmlParser->getUrls(cur); //another thread can come here while this is running.
				 lk.lock();
				 for (string neighbor : neighbors) {
					 if (shareHostName(neighbor, cur)) {
						 q.push(neighbor);
             cv.notify_all();
					 }	
				 }
			 }
		 }
		 lk.unlock();
	 }


	 vector<string> crawl(string startUrl, HtmlParser htmlParser) {
		 int threadNum = thread::hardware_concurrency();
		 vector<thread> workers;
		 q.push(startUrl);
		 for (int i = 0; i < threadNum; ++i) {
			 workers.push_back(thread(&Solution::startCrawling, this, &htmlParser));
		 }

		 for (auto& it : workers) {
			 it.join();
		 }

		 return vector<string>(visited.begin(), visited.end());
	 }

