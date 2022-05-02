//Программа демонстрирует управление цветом текста и фона 
//при помощи ESCAPE-последовательностей

# include <stdio.h>

int main(int argc, char *argv[])
{
    int fgbg,color;
    
    for(fgbg=38;fgbg<=48;fgbg+=10){
	for(color=0;color<=256;color++){
	    printf("\e[%d;5;%dm %d\t\e[0m",fgbg,color,color);
	    if((color +1)%10==0) printf("\n");
	}
	printf("\n");
    }
    
    return 0;
}
