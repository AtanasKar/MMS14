void Reverse(char* ptr){
    char temp;
    unsigned length=0;

    for (int i = 0; ptr[i]!='\0'; i++)
    {
        length++;
    }
    
    for (int i = 0,j=length-1; i<length/2; i++,j--)
    {
        temp=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=temp;
    }
}

int main(){
    

    return 0;
}