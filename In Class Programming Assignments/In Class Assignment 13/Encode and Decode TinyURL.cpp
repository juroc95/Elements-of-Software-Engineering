// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 13

class Solution
{
public:
    unordered_map<string, string> shortDB, longDB;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string getUrl()
    {
        string url = "";
        for (int i = 0; i < 6; i++)
            url += chars[rand() % 62];
        return "http://tinyurl.com/" + url;
    }

    string encode(string longUrl)
    {
        if (longDB.find(longUrl) != longDB.end())
            return longDB[longUrl];
        string shortUrl = getUrl();
        while (shortDB.find(shortUrl) != shortDB.end())
            shortUrl = getUrl();
        shortDB[shortUrl] = longUrl;
        longDB[longUrl] = shortUrl;
        return shortUrl;
    }

    string decode(string shortUrl)
    {
        return shortDB[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));