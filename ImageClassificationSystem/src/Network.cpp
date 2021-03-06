/*
 * Network.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: ibrahim
 */

#include "Network.h"

Network* Network::make_network(int n) {
    Network *net = (Network *)calloc(1, sizeof(Network));
    net->n = n;
    net->layers = (Layer *)calloc(net->n, sizeof(Layer));
    return net;
}

Layer Network::get_network_output_layer() {
	return this->layers[n - 1];
}

void Network::forward_network() {
	Network *net = this;
	int i;
	//net.layers = net.layers - 4;
	for (i = 0; i < n; ++i) {
		net->index = i;
		Layer *l = &net->layers[i]; // Issue: first layer has wrong type: Softmax!!!

		if(l->type == Layer_Type::SOFTMAX) continue; // just to solve the issue temporarely
		/*if (l.getType() == Layer_Type::CONVOLUTIONAL) {
			Convolutional_layer layer = *(Convolutional_layer)(net.layers[i]);
			layer.forward_convolutional_layer(net);
		} else if (l.getType() == Layer_Type::CONNECTED) {
			Connected_layer layer = *(Connected_layer *) net.layers[i];
			layer.forward_connected_layer(net);
		} else if (l->getType() == Layer_Type::MAXPOOL) {
			Maxpool_layer *maxpool_layer;
			maxpool_layer->copy_layer(l);
			maxpool_layer->forward_layer(net);
			net->input = l->getOutput();
		} else if (l.getType() == Layer_Type::DROPOUT) {
			Dropout_layer layer = *(Dropout_layer *) net.layers[i];
			layer.forward_dropout_layer(net);
		} else if (l->getType() == Layer_Type::SOFTMAX) {
			Softmax_layer *soft_layer;
			soft_layer->copy_layer(l);
			soft_layer->forward_layer(net);
			net->input = l->getOutput();
		}*/
		//l->forward_layer(net);
		//net->input = l->getOutput();
	}
}

float* Network::network_predict(float *input) {
    Network orig = *this;
    this->input = input;
    this->delta = 0;
    this->forward_network();
    float *out = this->output;
    *this = orig;
    return out;
}

