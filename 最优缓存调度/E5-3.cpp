#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_in_cache(const vector<char>& cache, char c) {
    for (char ch : cache) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}

void process_requests(int cache_size, int request_length, const vector<char>& initial_cache, const vector<char>& requests) {
    vector<char> cache;
    unordered_map<char, int> last_used;

    for (char c : initial_cache) {
        cache.push_back(c);
        last_used[c] = -1;
    }

    for (char c : requests) {
        if (is_in_cache(cache, c)) {
            cout << "no exchange" << endl;
        }
        else {
            char to_replace;
            if (cache.size() < cache_size) {
                cache.push_back(c);
                to_replace = ' ';
            }
            else {
                int idx = 0;
                int least_recently_used = request_length + 1;
                for (char ch : cache) {
                    if (last_used[ch] < least_recently_used) {
                        least_recently_used = last_used[ch];
                        to_replace = ch;
                    }
                    last_used[ch]++;
                }
                for (int i = 0; i < cache.size(); i++) {
                    if (cache[i] == to_replace) {
                        cache[i] = c;
                        last_used[c] = 0;
                        break;
                    }
                }
            }
            cout << to_replace << endl;
        }
    }
}

int main() {
    int cache_size, request_length;
    cout << "缓存大小N、请求序列的长度、初始阶段在缓存的变量、请求序列" <<endl;
    cin >> cache_size >> request_length;

    vector<char> initial_cache(cache_size);
    for (int i = 0; i < cache_size; i++) {
        cin >> initial_cache[i];
    }

    vector<char> requests(request_length);
    for (int i = 0; i < request_length; i++) {
        cin >> requests[i];
    }

    cout << endl;
    process_requests(cache_size, request_length, initial_cache, requests);
    system("pause");
    return 0;
}