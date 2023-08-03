#include <stdio.h>
#include <stdlib.h>
#include "imagelib.h"

void equaliza(image In, image Out, int nl, int nc, int mn){
    int i;
    int histograma[mn + 1 ];
    int sk[mn + 1 ]; //pixel equalizado
    float pk[mn + 1]; //probabilidade dos pixels
    float ak[mn + 1]; //probabilidade acumulada

    for(i = 0; i < mn; i++)
        histograma[i] = 0;
    for(i = 0; i < nl * nc; i++)
        histograma[In[i]]++;
    histograma[255]++;
    for(i = 0; i < mn; i++){
        pk[i] = (float) histograma[i] /(nl * nc);
        printf(" pk[%d] = %.2f", i, pk[i]);
    }
    pk[255] = (float) histograma[255]/(nl * nc);
    ak[0] = pk[0];
    for(i = 0; i < mn; i++){
        ak[i] = ak[i - 1] + pk[i];
        printf(" ak[%d] = %.2f", i, ak[i]);
    }
    ak[255] = ak[254] + pk[255];
    for(i = 0; i < mn; i++){
        sk[i] = ak[i] * mn;
        printf(" sk[%d] = %d",i,sk[i]);
    }
    sk[255] = ak[255] * mn;
    for(i = 0; i < nl * nc; i++)
        Out[i] = sk[In[i]];
}

void msg(char *s){
    printf("\nImage equalizada");
    printf("\n--------------------------");
    printf("\nUsage: %s <IMG.PGM>\n\n", s);
    printf("    <IMG.PGM is pgm image file\n\n");
    exit(1);
}

int main(int argc, char *argv[]){
    int OK, nc, nr, ml;
    char name[100];
    char command[110];
    image In, Out;
    if(argc < 2)
        msg(argv[0]);

    In = img_readpgm(argv[1], &nr, &nc, &ml);
    Out = img_alloc(nr,nc);
    printf("\nHistograma");
    img_info(argv[1], nr, nc, ml);

    equaliza(In, Out, nr, nc, ml);

    sprintf(name, "%s-%s",argv[1],"equaliza.pgm");
    img_writepgm(Out, name, nr, nc, ml);
    sprintf(command, "%s %s &", VIEW, name);
    system(command);
    img_free(In);
    img_free(Out);
    return 0;
}