class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        counter = {}
        maxHeap = []
        res = ""
        for c in s:
            if c in counter:
                counter[c]+=1
            else:
                counter[c]=1
        for key,value in counter.items():
            heapq.heappush(maxHeap, (-value,key))
        while maxHeap:
            freq,character = -maxHeap[0][0],maxHeap[0][1]
            heapq.heappop(maxHeap)
            for _ in range(freq):
                res = res + character
            heapq.heapify(maxHeap)
        return res