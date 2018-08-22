#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Perceptron
# El modelo matemático mas simple de una neurona es un percptron.
# El perceptron en las RNA recibe como señal de entrada el producto punto de los valores de entrada
# y los pesos asociados a las mismas, produce una salida usando una funcón de activación mediante un
# conjunto de reglas y un
#  
#  


def sand(a,b):
    return a and b

def main(args):
    entrada =[]
    entrada.append((0,0))
    entrada.append((0,1))
    entrada.append((1,0))
    entrada.append((1,1))
    theta=0;
    w1=0
    w2=0
    satisfecho=0
    epoca=1
    while (satisfecho!=4):
        print "epoca"+str(epoca)
        satisfecho=0
        for p,e in enumerate(entrada):
            print "p"+str(p)
            s=(w1*e[0])+(w2*e[1])
            if s>theta:
                sp=1
            else:
                sp=0
            print "sp_"+str(sp)
            sd=sand(e[0],e[1])
            print  "w1_"+str(w1)+"w2"+str(w2)+"theta"+str(theta)
            print "vs"
            print  sp,sd
            if sp==0 and sd==1:
                print "ajustar_pesos"
                print "aumento pesos disminuye umbral"
                theta=theta-1
                w1=w1+((sd-sp)*e[0])
                w2=w2+((sd-sp)*e[1])
            elif sp==1 and sd==0:
                theta=theta+1
                w1=w1+((sd-sp))*e[0]
                w2=w2+((sd-sp))*e[1]
            else:
                satisfecho+=1
                print "son iguales "
            print "____"
        epoca+=1
                
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
 
 
