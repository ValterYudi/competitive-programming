n, q = map(int, input().split())
heights = list(map(int, input().split()))

# Process queries
for _ in range(q):
    query_type, i, H = map(int, input().split())
    i -= 1  # Convert to 0-indexing
    
    if query_type == 1:
        # Update mansion height
        heights[i] = H
    else:
        # Calculate number of mansions they can visit
        count = 1  # Start with the current mansion
        
        # Check left neighbors
        left = i - 1
        while left >= 0 and abs(heights[left] - heights[left+1]) <= H:
            count += 1
            left -= 1
        
        # Check right neighbors
        right = i + 1
        while right < n and abs(heights[right] - heights[right-1]) <= H:
            count += 1
            right += 1
        
        print(count)
