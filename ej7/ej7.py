import multiprocessing as mp

def pi(n,m):
  r=0
  for i in range(n,m+1):
    r+=(-1)**(i+1)/((2*i)*(2*i+1)*(2*i+2))
  return (r)

if __name__=="__main__":
    pool=mp.Pool()
    limite=10**5//2
    num_proc= mp.cpu_count()
    #print(num_proc)
    parametros = [ ( (i*limite+1),(limite*(i+1)) ) for i in range(num_proc) ]
    #print(parametros)
    resultado = pool.starmap(pi,parametros)
    resultado = 3+4*(sum(resultado))
    print(f"Valor-pi: {resultado}")