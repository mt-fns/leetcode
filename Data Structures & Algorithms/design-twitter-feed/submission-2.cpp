class Twitter {
// fetchest at most 10 recent tweet ids
// the 10 most recent either comes from the user themselves or any followings
// store a following list for each user -> map {id: following}
// store a feed for each user -> store 

// what if we create a feed list for each user instead
// when new user posts, check all of the ppl following them then add that to the most recent queue of all their followings
// insertion -> O(nlog10) -> O(n)
// get -> O(log10) -> O(1)
// follow -> add to the user being followed's followed list O(1)
// unfollow -> remove from the user being followed's followed list O(n)


// store heap for each person's post -> only 10 most recent ones
// when getting feed, merge all heap from all followers -> O(nlog10)


private:
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> posts;
    map<int, vector<int>> followings;
    int time;

    void addPost(int userId, int tweetId, int time) {
        posts[userId].push({time, tweetId});

        // only store 10 most recent post by userId
        if (posts[userId].size() > 10) {
            posts[userId].pop();
        }
    }

public:
    Twitter() {
        time = 0;
    }
    
    // check that heap for userId already exists
    void postTweet(int userId, int tweetId) {
        addPost(userId, tweetId, time);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> feed;

    // make user follow themselves
    if (!count(followings[userId].begin(), followings[userId].end(), userId)) {
        followings[userId].push_back(userId);
    }
    
    // Add followings' posts
    for (int following : followings[userId]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> followingPosts = posts[following];
        while (!followingPosts.empty()) {
            feed.push(followingPosts.top());
            followingPosts.pop();
            if (feed.size() > 10) {
                feed.pop();
            }
        }
    }

    vector<int> res;
    while (!feed.empty()) {
        res.insert(res.begin(), feed.top().second);
        feed.pop();
    }

    return res;
}
    
    // check that heap for both already exist
    void follow(int followerId, int followeeId) {
        if (!count(followings[followerId].begin(), followings[followerId].end(), followeeId)) {
            followings[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (count(followings[followerId].begin(), followings[followerId].end(), followeeId)) {
            erase(followings[followerId], followeeId);
        }
    }
};
