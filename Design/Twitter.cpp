class Twitter {
public:
	/** Initialize your data structure here. */

	map<int, int> Tweet2User; //tweet id -> user id of tweeter
	map<int, set<int>> users; //user id -> follower id
	map<int, deque<int> > tweets; // user id -> tweet ids user cares about

	Twitter() {}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		Tweet2User[tweetId] = userId;
		tweets[userId].push_front(tweetId); //push my own tweet to the front of my newsfeed
		set<int> myFollowers = users[userId];
		for (int follower : myFollowers) {
			tweets[follower].push_front(tweetId);
		}

	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		set<int> myFollowers = users[userId];
		deque<int> q = tweets[userId];
		vector<int> mostRecentTweets;
		for (int tweetId : q) {
			int tweeterId = Tweet2User[tweetId];
			set<int> myFollowers = users[tweeterId];
			auto it = myFollowers.find(userId);
			if (it != myFollowers.end() || tweeterId == userId) {
				mostRecentTweets.push_back(tweetId);
			}
			if (mostRecentTweets.size() == 10) {
				break;
			}
		}
		return mostRecentTweets;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		//users[followeeId].push(followerId);
		users[followeeId].insert(followerId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		auto it = users[followeeId].find(followerId);
		if (it != users[followeeId].end()) {
			//followers.erase(it);
			users[followeeId].erase(it);
		}
	}
};




void main() {
	
	/*
	["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
	[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
	
	Twitter* t = new Twitter();
	t->postTweet(1, 5); //user1 posted tweet5
	t->getNewsFeed(1); //output should be 5
	t->follow(1, 2); //user1 follows user2
	t->postTweet(2, 6); //user2 tweets tweet6
	vector<int> res = t->getNewsFeed(1); //[6,5]
	t->unfollow(1, 2); //user1 unfollows user2
	t->getNewsFeed(1); //output should be [5]
	*/
	/*
	["Twitter","postTweet","getNewsFeed","follow","getNewsFeed","unfollow","getNewsFeed"]
	[[],[1,1],[1],[2,1],[2],[2,1],[2]]
	*/
	Twitter* t = new Twitter();
  }
