import math
import multiprocessing as mp

def fibo(inicial,final):
  v=[]
  for i in range(inicial,final):
    p=(((1+math.sqrt(5))/2)**i / math.sqrt(5))+1/2
    v.append(int(p))
  return v

if __name__=="__main__":
  limite=368
  num_proc= mp.cpu_count()
  parametros = [ ((i*limite),(limite*(i+1))) for i in range(num_proc)]
  #print(parametros)
  pool = mp.Pool()
  r = pool.starmap(fibo , parametros)
  for i in r:
    print(i)