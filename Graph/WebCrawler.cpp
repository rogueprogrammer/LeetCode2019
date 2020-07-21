  // https://leetcode.com/problems/web-crawler/
  string getHostName(string url){
        // http://leetcode.com/problems
        return url.substr(0, url.find("/", 7));
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        string hostName = getHostName(startUrl);
        queue<string> q;
        q.push(startUrl);
        
        set<string> s; //record all visited urls
        s.insert(startUrl);
        
        while(!q.empty()){
            string curUrl = q.front();
            vector<string> correspondingUrls = htmlParser.getUrls(curUrl);
            for(string correspondingUrl : correspondingUrls){
                if(getHostName(correspondingUrl) == hostName){
                    auto it = s.find(correspondingUrl);
                    if(it == s.end()){
                        s.insert(correspondingUrl);
                        q.push(correspondingUrl);
                    }
                }
            }
            q.pop();
        }
        vector<string> res(s.begin(), s.end());
        return res;
    }
