

# Implementacion de un red neuronal artificial 
# que resuelve el problema del xor
# usando la libreria tensorflow

import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt

num_caracteristicas = 2
num_iter = 10000
display_step = int(num_iter / 10)
tasa_aprendizaje = 0.01

num_entrada = 2          # numero de neuronas en la caa
num_nocultas = 2        # units in the first hidden layer
num_nsalida = 1         # units in the output, only one output 0 or 1


def multi_layer_perceptron_xor(x, weights, biases):

    capa_oculta1 = tf.add(tf.matmul(x, weights['w_h1']), biases['b_h1'])
    capa_oculta1 = tf.nn.sigmoid(capa_oculta1)

    capa_salida = tf.add(tf.matmul(capa_oculta1, weights['w_out']), biases['b_out'])

    return capa_salida


x = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], np.float32)  # entrada 4x2
y = np.array([0, 1, 1, 0], np.float32)                      # salida correta de la operación 
y = np.reshape(y, [4,1])                                    # transformar la salida a 4*1 para la operación entre vectores


X = tf.placeholder('float', [None, num_entrada])    
Y = tf.placeholder('float', [None, num_nsalida])    

# weights and biases
weights = {
    'w_h1' : tf.Variable(tf.random_normal([num_entrada, num_nocultas])), #pesos de la capa de entrada a la capa oculta
    'w_out': tf.Variable(tf.random_normal([num_nocultas, num_nsalida])) # pesos de la capa oculta a la capa de salida
}
biases = {
    'b_h1' : tf.Variable(tf.zeros([num_nocultas])),
    'b_out': tf.Variable(tf.zeros([num_nsalida]))
}

model = multi_layer_perceptron_xor(X, weights, biases)


loss_func = tf.reduce_sum(tf.nn.sigmoid_cross_entropy_with_logits(logits=model, labels=Y))
optimizer = tf.train.GradientDescentOptimizer(learning_rate=tasa_aprendizaje).minimize(loss_func)

sess = tf.Session()
init = tf.global_variables_initializer()
sess.run(init)
# Realiza el entrenamiento
for k in range(num_iter):
    tmp_cost, _ = sess.run([loss_func, optimizer], feed_dict={X: x, Y: y})
    if k % display_step == 0:
        #print('output: ', sess.run(model, feed_dict={X:x}))
        print('loss= ' + "{:.5f}".format(tmp_cost))


W = np.squeeze(sess.run(weights['w_h1']))   # 2x2
b = np.squeeze(sess.run(biases['b_h1']))    # 2,

sess.close()


