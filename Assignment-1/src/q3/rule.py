from main import *
def rule(cell_value: int, neighbours: "list[int]") -> int:
    if(neighbours[2]+neighbours[3] > 0):
        return int(1)
    return cell_value
