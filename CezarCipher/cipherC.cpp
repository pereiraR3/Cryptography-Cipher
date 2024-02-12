#include <iostream> 
using namespace std;

typedef struct ctext{
    string ciphertext; 
    int statusCipher = 0; 
}ctext;

class cipherC{

    public:

        string plaintext;
        int displacement; 
        ctext cipher;

        cipherC(string inputPlaintext, int inputDisplacement){
            setPlaintext(inputPlaintext); 
            setDisplacement(inputDisplacement);
        }

        string getPlaintext(){
            return plaintext;
        } 

        int getDisplacement(){ 
            return displacement; 
        }

        string getCiphertext(){
            return cipher.ciphertext;
        }

        void setPlaintext(string input){
            plaintext = input; 
        }

        void setDisplacement(int input){
            displacement = input;
        }


        void makeCipher(){
            try{
                cipher.ciphertext = getPlaintext();
                char baseUp = 'A';
                char baseS = 'a';
                for(int i = 0; i < cipher.ciphertext.size(); i++){
                    if(isalpha(cipher.ciphertext[i])){
                        if(isupper(cipher.ciphertext[i])){
                                cipher.ciphertext[i] = char(int(baseUp) + (cipher.ciphertext[i] - baseUp + getDisplacement()) % 26);
                        }else{
                            cipher.ciphertext[i] = char(int(baseS) + (cipher.ciphertext[i] - baseS + getDisplacement()) % 26);
                        }
                    }
                }
                cipher.statusCipher = 1; 
            }catch(exception& e){
                string messageError = e.what(); 
                cerr << "Error: " << messageError << endl;
            }
        }

        void cipherToPlain(){
            try{
                if(cipher.statusCipher){
                    char baseUp = 'A';
                    char baseS = 'a';
                    for(int i = 0; i < cipher.ciphertext.size(); i++){
                        if(isalpha(cipher.ciphertext[i])){
                            if(isupper(cipher.ciphertext[i])){
                                cipher.ciphertext[i] = char(int(baseUp) + (cipher.ciphertext[i] - baseUp - getDisplacement() + 26) % 26);
                            }else{
                                cipher.ciphertext[i] = char(int(baseS) + (cipher.ciphertext[i] - baseS - getDisplacement() + 26) % 26);
                            }
                        }
                    }
                    cipher.statusCipher = 0;
                }else{
                    throw "Error cipher";
                }
            }catch(exception& e){
                string messageError = e.what(); 
                cerr << "Error: " << messageError << endl;
            }
        }

};

int main(){

    cipherC *cipher = new cipherC("aaXZxz32", 3);
    cipher->makeCipher();
    cout << "Normal text: " << cipher->getPlaintext() << endl;
    cout << "Ciphertext: " << cipher->getCiphertext() << endl;
    cipher->cipherToPlain();
    cout << "Cipher to Plain: " << cipher->getCiphertext() << endl;

}