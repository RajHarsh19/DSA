class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}        # Stores key → value
        self.usage_order = []  # Tracks key usage from least to most recent

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        # Move the key to the end to mark it as recently used
        self.usage_order.remove(key)
        self.usage_order.append(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update value and move key to end
            self.cache[key] = value
            self.usage_order.remove(key)
            self.usage_order.append(key)
        else:
            if len(self.cache) >= self.capacity:
                # Evict least recently used key
                lru_key = self.usage_order.pop(0)
                del self.cache[lru_key]
            self.cache[key] = value
            self.usage_order.append(key)

        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)