class DynamicArray {
private:
    int *v;
    int capacity;
    int cont;
public:

    DynamicArray(int capacity) {
        this->v = (int *)malloc(sizeof(int)*capacity);
        this->cont = -1;///adica nu avem niciun element introdus
        this->capacity = capacity;
    }

    int get(int i) {
        return (this->v)[i];
    }

    void set(int i, int n) {
        (this->v)[i] = n;
    }

    void pushback(int n) {
        if(this->capacity == this->cont +1)
            resize();
        (this->v)[++this->cont] = n;
    }

    int popback() {
        if (cont != -1)
            return (this->v)[this->cont --];
        else
            return 0;
    }

    void resize() {
        this->capacity *= 2;
        this->v = (int *)realloc(this->v,this->capacity*(sizeof(int)));
    }

    int getSize() {
        return (this->cont+1);
    }

    int getCapacity() {
        return (this->capacity);
    }
};
