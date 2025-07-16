class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(currentIndex, row, col,visited):
            if currentIndex == len(word):
                return True
            if row<0 or row>=len(board) or col<0 or col>=len(board[0]) or visited[row][col] or word[currentIndex] != board[row][col] :
                return False
            visited[row][col] = True
            if (dfs(currentIndex+1,row+1,col,visited) or
                dfs(currentIndex+1,row,col+1,visited) or
                dfs(currentIndex+1,row-1,col,visited) or
                dfs(currentIndex+1,row,col-1,visited)):
                    return True
            visited[row][col] = False
            return False
        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == word[0]:
                    visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
                    if dfs(0,row,col,visited):
                        return True
        return False
