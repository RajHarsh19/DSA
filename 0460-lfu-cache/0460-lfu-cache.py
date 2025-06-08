class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}  # key -> [value, freq]
        self.freq_map = {}  # freq -> [keys in LRU order]
        self.min_freq = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        val, freq = self.cache[key]
        self.freq_map[freq].remove(key)

        if not self.freq_map[freq]:
            del self.freq_map[freq]
            if self.min_freq == freq:
                self.min_freq += 1

        self.cache[key][1] += 1
        freq += 1
        if freq not in self.freq_map:
            self.freq_map[freq] = []
        self.freq_map[freq].append(key)

        return val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.cache:
            self.cache[key][0] = value
            self.get(key)  # update frequency
            return

        if len(self.cache) >= self.capacity:
            # Remove LFU item
            lfu_key = self.freq_map[self.min_freq][0]
            self.freq_map[self.min_freq].remove(lfu_key)
            if not self.freq_map[self.min_freq]:
                del self.freq_map[self.min_freq]
            del self.cache[lfu_key]

        self.cache[key] = [value, 1]
        if 1 not in self.freq_map:
            self.freq_map[1] = []
        self.freq_map[1].append(key)
        self.min_freq = 1

        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)