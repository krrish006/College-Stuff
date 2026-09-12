#include<stdio.h>
#include <math.h>
#include<stdlib.h>
    

    #define lr 0.0001
    #define delta_x 0.0001

    

    float sigmoid(float x)
    {
        return 1.0f / (1.0f + expf(-x));
    }

    struct NEURON_L1  //784
    {
        float activation;   //between 0 and 1 
        //have 0 connection to previous layer neuron (accepts DATA)
    };

    struct NEURON_L2 //100
    {
        float activation;   //between 0 and 1 
        float weight[784];   //have 784 (no of neruon [784 pixel]) connection to previous layer neuron
        float bias;          //Bias
    };

    struct NEURON_L3 //100
    {
        float activation;   //between 0 and 1 
        float weight[100];   //have 100 connection to previous layer neuron
        float bias;          //Bias
    };

    struct NEURON_L4 //10
    {
        float activation;   //between 0 and 1 
        float weight[100];   //have 100 connection to previous layer neuron (final layer)
        float bias;          //Bias
    };



    void save_L2(struct NEURON_L2 layer[])      //saves progress for L2
    {

        FILE *f = fopen("L1-L2.txt", "w");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 784; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fprintf(f,"%f ",layer[i].weight[j]);
            }
            fprintf(f,"%f \n",layer[i].bias);
            
        }

        fclose(f);
    }

    void save_L3(struct NEURON_L3 layer[])      //saves progress for L3
    {

        FILE *f = fopen("L2-L3.txt", "w");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fprintf(f,"%f ",layer[i].weight[j]);
            }
            fprintf(f,"%f \n",layer[i].bias);
            
        }

        fclose(f);
    }

    void save_L4(struct NEURON_L4 layer[])      //saves preogress for L4
    {

        FILE *f = fopen("L3-L4.txt", "w");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 100; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fprintf(f,"%f ",layer[i].weight[j]);
            }
            fprintf(f,"%f \n",layer[i].bias);
            
        }

        fclose(f);
    }

    void load_L2(struct NEURON_L2 layer[])      //loads progress for L2
    {

        FILE *f = fopen("L1-L2.txt", "r");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 784; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fscanf(f, "%f", &layer[i].weight[j]);
            }
            fscanf(f, "%f", &layer[i].bias);
            
        }

        fclose(f);
    }

    void load_L3(struct NEURON_L3 layer[])      //loads progress for L3
    {

        FILE *f = fopen("L2-L3.txt", "r");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fscanf(f, "%f", &layer[i].weight[j]);
            }
            fscanf(f, "%f", &layer[i].bias);
            
        }

        fclose(f);
    }

    void load_L4(struct NEURON_L4 layer[])      //loads progress for L4
    {

        FILE *f = fopen("L3-L4.txt", "r");  //opens files 

        if (f == NULL) {
            printf("Error opening file for read\n");    //checks if it had opened properly
            return;
        }

        
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 100; j++)           // i -> neuron number
            {                                       // j -> neuron parameter 
                fscanf(f, "%f", &layer[i].weight[j]);
            }
            fscanf(f, "%f", &layer[i].bias);
            
        }

        fclose(f);
    }

    void feed(struct NEURON_L1 input[],int *data ,int *digi)
    {
        FILE *f = fopen("mnist_test.csv", "r");  //opens files 

        if (f == NULL) {
            printf("Error opening database for read\n");    //checks if it had opened properly
            return;
        }

        float value;

        for (int i = 0; i < (*digi)*785; i++)
        {
            fscanf(f, "%f ,", &value);              //skip digit
        }

        fscanf(f, "%d ,", data);
        

        for (int i = 0; i < 784; i++)
        {
            fscanf(f, "%f ,", &value);

            input[i].activation = value/255.0f;
        }

        (*digi)++;

        fclose(f);
        
    }

    void propogate1(struct NEURON_L1 input[],struct NEURON_L2 hidden1[])
    {

        for (int j = 0; j < 100; j++)          // outer: which neuron in hidden1
        {
            hidden1[j].activation = 0;          // reset THIS neuron's sum

            for (int i = 0; i < 784; i++)       // inner: sum over all 784 inputs
            {
                hidden1[j].activation += input[i].activation * hidden1[j].weight[i];
            }

            hidden1[j].activation += hidden1[j].bias;              // once, after the sum
            hidden1[j].activation = sigmoid(hidden1[j].activation); // once, after bias
        }
        
    }

    void propogate2(struct NEURON_L2 hidden1[],struct NEURON_L3 hidden2[])
    {

        for (int j = 0; j < 100; j++)          // outer: which neuron in hidden2
        {
            hidden2[j].activation = 0;          // reset THIS neuron's sum

            for (int i = 0; i < 100; i++)       // inner: sum over all 100 inputs
            {
                hidden2[j].activation += hidden1[i].activation * hidden2[j].weight[i];
            }

            hidden2[j].activation += hidden2[j].bias;              // once, after the sum
            hidden2[j].activation = sigmoid(hidden2[j].activation); // once, after bias
        }
        
    }

    void propogate3(struct NEURON_L3 hidden2[],struct NEURON_L4 output[])
    {

        for (int j = 0; j < 10; j++)          // outer: which neuron in hidden2
        {
            output[j].activation = 0;          // reset THIS neuron's sum

            for (int i = 0; i < 100; i++)       // inner: sum over all 100 inputs
            {
                output[j].activation += hidden2[i].activation * output[j].weight[i];
            }

            output[j].activation += output[j].bias;              // once, after the sum
            output[j].activation = sigmoid(output[j].activation); // once, after bias
        }
        
    }

    float result(int *data,int *digi,struct NEURON_L1 input[],struct NEURON_L2 hidden1[],struct NEURON_L3 hidden2[],struct NEURON_L4 output[],int proceed_to_next_digit)
    {
        if (proceed_to_next_digit == 1)
        {
            feed(input,data,digi);
        }

        
        propogate1(input,hidden1);
        propogate2(hidden1,hidden2);
        propogate3(hidden2,output);

        float cf = 0;
        float vec[10] = {0.0f};

        vec[*data] = 1.0f;


        for (int i = 0; i < 10; i++)
        {
            cf += (output[i].activation-vec[i])*(output[i].activation-vec[i]);
        }

        return cf;
    }

    float differentate(float cf,int layer,int neuron,int weight_no,int *data, int *digi, struct NEURON_L1 input[], struct NEURON_L2 hidden1[], struct NEURON_L3 hidden2[], struct NEURON_L4 output[], int proceed_to_next_digit)           //calculates d(cf)/dw
    {

        float cff = 0;

        

        if (layer == 2)
        {
            hidden1[neuron].weight[weight_no] += delta_x;

            cff = result(data,digi,input,hidden1,hidden2,output,0);
            hidden1[neuron].weight[weight_no] -= delta_x;
            return (cff-cf)/delta_x;

            
        }
        else if (layer == 3)
        {
            hidden2[neuron].weight[weight_no] += delta_x;

            cff = result(data,digi,input,hidden1,hidden2,output,0);
            hidden2[neuron].weight[weight_no] -= delta_x;
            return (cff-cf)/delta_x;

            
        }
        else if (layer == 4)
        {
            output[neuron].weight[weight_no] += delta_x;

            cff = result(data,digi,input,hidden1,hidden2,output,0);
            output[neuron].weight[weight_no] -= delta_x;
            return (cff-cf)/delta_x;

            
        }
        
    }

    void train_L4(struct NEURON_L3 hidden2[],struct NEURON_L4 output[],float basis[],float L4grad[][101])      //be sure to let the network run before any traning
    {
        // float gradient[100];    //w1 ,w2 ,w3 ....,b

        float derevative = 0;

        for (int i = 0; i < 10; i++)       //cycle through neuron
        {
            for (int j = 0; j < 100; j++)   //cycle through parameter(weights)
            {
                derevative = 2*(output[i].activation-basis[i])*output[i].activation*output[i].activation*((1.0/output[i].activation)-1)*hidden2[j].activation;
                // gradient[j] = derevative;
                output[i].weight[j] = output[i].weight[j] - derevative*lr;
                L4grad[i][j] = derevative;
            }
            derevative = 2*(output[i].activation-basis[i])*output[i].activation*output[i].activation*((1.0/output[i].activation)-1);    //for bias
    
            // gradient[100] = derevative;
            output[i].bias = output[i].bias - derevative*lr;
            L4grad[i][100] = derevative;

        }
        save_L4(output);
        
    }

    // void train_L3(struct NEURON_L3 hidden2[],struct NEURON_L4 output[],float L4grad[][101])      //be sure to let the network run before any traning
    // {
    //     // float gradient[100];    //w1 ,w2 ,w3 ....,b

    //     float derevative;

    //     for (int i = 0; i < 100; i++)       //cycle through neuron
    //     {
    //         for (int j = 0; j < 100; j++)   //cycle through parameter(weights)
    //         {
    //             for (int k = 0; k < 10; k++) //cycle through back neuron
    //             {
                    
    //             }
                
    //         }
            
    //     }
        
        
    // }


    //the below code is AI i will write my later

    void train_L3(struct NEURON_L2 hidden1[], struct NEURON_L3 hidden2[], struct NEURON_L4 output[], float L4grad[][101], float L3grad[][101])
    {
        for (int j = 0; j < 100; j++)          // cycle through hidden2 neurons
        {
            float sum = 0;
            for (int k = 0; k < 10; k++)       // sum contribution from every output neuron
            {
                sum += L4grad[k][100] * output[k].weight[j];
            }

            float hidden2_delta = sum * hidden2[j].activation * (1.0f - hidden2[j].activation);

            for (int i = 0; i < 100; i++)      // update this neuron's weights
            {
                hidden2[j].weight[i] -= lr * hidden2_delta * hidden1[i].activation;
                L3grad[j][i] = hidden2_delta;   // stash it (same pattern as L4grad), needed for train_L2
            }
            hidden2[j].bias -= lr * hidden2_delta;
            L3grad[j][100] = hidden2_delta;     // this is hidden2[j]'s own delta, no per-weight variation needed
        }
        save_L3(hidden2);
    }

    void train_L2(struct NEURON_L1 input[], struct NEURON_L2 hidden1[], struct NEURON_L3 hidden2[], float L3grad[][101])
    {
        for (int j = 0; j < 100; j++)          // cycle through hidden1 neurons
        {
            float sum = 0;
            for (int k = 0; k < 100; k++)      // sum contribution from every hidden2 neuron
            {
                sum += L3grad[k][100] * hidden2[k].weight[j];
            }

            float hidden1_delta = sum * hidden1[j].activation * (1.0f - hidden1[j].activation);

            for (int i = 0; i < 784; i++)      // update this neuron's weights
            {
                hidden1[j].weight[i] -= lr * hidden1_delta * input[i].activation;
            }
            hidden1[j].bias -= lr * hidden1_delta;
        }
        save_L2(hidden1);
    }


    void randomize_L2(struct NEURON_L2 layer[])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 784; j++)
        {
            layer[i].weight[j] = ((float)rand() / RAND_MAX) - 0.5f;
        }
        layer[i].bias = ((float)rand() / RAND_MAX) - 0.5f;
    }
}

void randomize_L3(struct NEURON_L3 layer[])
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            layer[i].weight[j] = ((float)rand() / RAND_MAX) - 0.5f;
        }
        layer[i].bias = ((float)rand() / RAND_MAX) - 0.5f;
    }
}

void randomize_L4(struct NEURON_L4 layer[])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            layer[i].weight[j] = ((float)rand() / RAND_MAX) - 0.5f;
        }
        layer[i].bias = ((float)rand() / RAND_MAX) - 0.5f;
    }
}










    int main()
    {
        struct NEURON_L1 input[784];
        struct NEURON_L2 hidden1[100];
        struct NEURON_L3 hidden2[100];
        struct NEURON_L4 output[10];

        int data;
        int digi = 0;


        load_L2(hidden1);
        load_L3(hidden2);
        load_L4(output);

        feed(input,&data,&digi);


        float cf = 0;
        float diff = 0;
        float bias[10] = {0};
        float L4grad[10][101];
        float L3grad[100][101];


        cf = result(&data,&digi,input,hidden1,hidden2,output,1);

        // randomize_L2(hidden1);
        // randomize_L3(hidden2);
        // randomize_L4(output);

        // save_L2(hidden1);
        // save_L3(hidden2);
        // save_L4(output);

        // digi = 200;


        for (int i = 0; i < 10000; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                bias[j] = 0;
            }
            
            bias[data] = 1;
            train_L4(hidden2,output,bias,L4grad);
            train_L3(hidden1,hidden2,output,L4grad,L3grad);
            train_L2(input,hidden1,hidden2,L3grad);
            
            cf = result(&data,&digi,input,hidden1,hidden2,output,1);

            printf("%d \n",i);
        }
        


        // diff = differentate(cf,2,0,0,&data,&digi,input,hidden1,hidden2,output,0);

        for (int i = 0; i < 10; i++)
        {
            printf("%f \n",output[i].activation);
        }

        // printf("%f",diff);
        

        return 0;
    }
