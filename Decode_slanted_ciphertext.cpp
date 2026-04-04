class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        string text = "";
        int cols = n/rows;
        for(int c = 0; c < cols; c++){
            for(int j = c; j < n; j+=cols+1){
                text += encodedText[j];
                
            }
        }
        int x = text.size()-1;
        while(x > 0 && text[x--] == ' ' ){
            text.pop_back();
        }
        return text;
    }
};

//Intution:: First thought of pattern within the encodedText , realised the sequence is at an interval of cols+1 
//Talking about cols , since size of string = Number of cells in matrix . Thus number of cols = number of cells/rows
