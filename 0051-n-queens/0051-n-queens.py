class Solution:
    def isSafe(self,board,row,col,n):
        for i in range(row):
            if board[i][col]=='Q':
                return False
        for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
            if board[i][j] == 'Q':
                return False
        for i, j in zip(range(row - 1, -1, -1), range(col + 1, n)):
            if board[i][j] == 'Q':
                return False
        return True
    def nQueens(self, board, row, n, ans):
        if row == n:
            ans.append([''.join(r) for r in board])
            return
        for col in range(n):
            if self.isSafe(board, row, col, n):
                board[row][col] = 'Q'
                self.nQueens(board, row + 1, n, ans)
                board[row][col] = '.'
    def solveNQueens(self, n):
        board = [['.' for _ in range(n)] for _ in range(n)]
        ans = []
        self.nQueens(board, 0, n, ans)
        return ans

        