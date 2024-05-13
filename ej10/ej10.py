import multiprocessing as mp

def seriePar(n,m):
    v=[]
    for i in range(n,m+1):
        v.append((i)*2)
    return v
if __name__=="__main__":
    pool=mp.Pool()
    limite=10**3//2
    num_proc= mp.cpu_count()
    #v=[0]*((limite*num_proc)+1)
    parametros = [ ( (i*limite+1),(limite*(i+1))) for i in range(num_proc) ]
    #print(parametros)
    r=pool.starmap(seriePar,parametros)
    print("Serie Par:")
    for i in r:
        print(i)