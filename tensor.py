class Tensor():
    def __init__(self, data, shape):
        self.data = data
        self.shape = shape
        self.Tensor = []

    def set_Tensor_shape(self,index=0,Tensor='null'):
        if Tensor == 'null':
            Tensor = self.Tensor

        if index == len(self.shape)-1 :
            for i in range(shape[index]):
                if self.data:
                    In = self.data[0]
                    if In - int(In) == 0:
                        Tensor.append(int(self.data[0]))
                    else:
                        Tensor.append(self.data[0])
                    self.data = self.data[1:]
                else :
                    Tensor.append(0)
            return Tensor

        for i in range(shape[index]):
            Tensor.append([])
            self.set_Tensor_shape(index=index+1,Tensor=Tensor[i])
        
        return Tensor

    
data = [float(x) for x in input().split()]
shape = [int(x) for x in input().split()]
tensor0 = Tensor(data=data,shape=shape).set_Tensor_shape()
print(tensor0)

    