#import rule
from main import *
def rule(cell_value: int, neighbours: "list[int]") -> int:
    cnt = neighbours[0]+neighbours[1]+neighbours[2]+neighbours[3]+neighbours[4]+neighbours[5]+neighbours[6]+neighbours[7]
    if(cell_value == 1):
        if(cnt < 2 or cnt >= 4):
            return 0
        else:
            return 1
    if(cell_value == 0):
        if(cnt == 3):
            return 1
        else:
            return 0
