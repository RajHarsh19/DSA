class Solution:
    def searchNext(self, word, board, row, col, index, m, n):
        if index == len(word):
            return True
        if row < 0 or col < 0 or row == m or col == n or board[row][col] != word[index] or board[row][col] == '!':
            return False

        c = board[row][col]
        board[row][col] = '!'

        top = self.searchNext(word, board, row - 1, col, index + 1, m, n)
        right = self.searchNext(word, board, row, col + 1, index + 1, m, n)
        bottom = self.searchNext(word, board, row + 1, col, index + 1, m, n)
        left = self.searchNext(word, board, row, col - 1, index + 1, m, n)

        board[row][col] = c
        return top or right or bottom or left

    def exist(self, board: list[list[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        index = 0

        for i in range(m):
            for j in range(n):
                if board[i][j] == word[index]:
                    if self.searchNext(word, board, i, j, index, m, n):
                        return True

        return False
