bool solution(vector<int> sequence) {
        //not really sure if this is the most optimal algo but here
        int count = 0;
        //first loop checks what happens if we remove the ith element. second checks for what happens if we remove (i+1)th element.
        //after this we return false if removing either of them still doesnt result in an increasing sequence.
        vector<int> temp = sequence;
        for (int i = 0; i < sequence.size()-1; i++) {
            if (sequence[i] >= sequence[i+1]) {
                sequence.erase(sequence.begin()+i);
                break;
            } 
        }
        for (int i = 0; i < temp.size()-1; i++) {
            if (temp[i] >= temp[i+1]) {
                temp.erase(temp.begin()+i+1);
                break;
            } 
        }
        bool isF = false;
        for (int i = 0; i < sequence.size()-1; i++) {
            if (sequence[i] >= sequence[i+1]) {
                isF = true;
                break;
            } 
        }
        for (int i = 0; i < temp.size()-1; i++) {
            if (temp[i] >= temp[i+1]) {
                if (isF)
                    return false;
                break;
            } 
        }
        return true;
}
