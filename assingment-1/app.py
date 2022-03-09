

# print(mat)

def create_rug(hight,width,symbol1,symbol2):
    mat=[["1" for j in range(width)] for i in range(hight)]

    for i in range(hight):
        for j in range(width):
            if i == 0 or i == hight-1 or j == 0 or j == width-1:
                mat[i][j]=symbol1
            elif (i%2==0 and j==width-2) :
                  mat[i][j]=symbol2 
            elif (i%2==0  and mat[i][j-1]==symbol1) :
                mat[i][j]=symbol2
            elif i%2!=0 and mat[i][j-2]==symbol1 or i%2!=0 and mat[i][j]:
                mat[i][j-2]=symbol1
            elif i%2!=0:
                mat[i][j]=symbol2
            
    
    for i in range(hight):
        print(mat[i])
    
 
        
create_rug(7,9,"@","-")
