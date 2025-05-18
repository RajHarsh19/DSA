from typing import List

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        result=[]

        def backtrack(index: int,path: str, value: int,last_operand: int):
            if index ==len(num):
                if value==target:
                    result.append(path)
                return
            for i in range(index,len(num)):
                if i != index and num[index]=='0':
                    break
                curr_str = num[index:i+1]
                curr_num = int(curr_str)

                if index ==0:
                    backtrack(i+1,curr_str,curr_num,curr_num)
                else:
                    backtrack(i + 1, path + '+' + curr_str, value + curr_num, curr_num)
                    
                    backtrack(i + 1, path + '-' + curr_str, value - curr_num, -curr_num)
                    
                    backtrack(i + 1, path + '*' + curr_str, value - last_operand + last_operand * curr_num, last_operand * curr_num)

        backtrack(0, "", 0, 0)
        return result

                

        