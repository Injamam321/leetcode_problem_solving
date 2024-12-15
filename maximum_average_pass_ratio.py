# 1792. Maximum Average Pass Ratio
# Python3 Solution! problem-1792

import heapq

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        # Benefit Calculation Function
        def benefit(passi, totali):
            return (passi + 1) / (totali + 1) - (passi / totali)
        
        # Step 1: Build a Max Heap (negative benefit for max heap)
        max_heap = []
        for passi, totali in classes:
            heapq.heappush(max_heap, (-benefit(passi, totali), passi, totali))
        
        # Step 2: Assign extra students
        for _ in range(extraStudents):
            neg_benefit, passi, totali = heapq.heappop(max_heap)
            passi += 1
            totali += 1
            heapq.heappush(max_heap, (-benefit(passi, totali), passi, totali))
        
        # Step 3: Calculate the average pass ratio
        total_ratio = 0
        for _, passi, totali in max_heap:
            total_ratio += passi / totali
        
        return total_ratio / len(classes)