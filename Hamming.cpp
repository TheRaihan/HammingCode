#include <bits/stdc++.h>
using namespace std;

char ptype;
int pbit;

class Sender
{
    string sn;
    int msglen, cdsize, arr[50], brr[50];
    string map[30] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

public:
    void setmsg()
    {
        cout << "Enter Message: ";
        cin >> sn;
    }

    int getCdSize()
    {
        msglen = sn.size();

        pbit = log2(msglen + 1) + 1;

        if ((msglen + 1 + pbit) > pow(2, pbit))
            pbit++;

        cout << pbit << endl;

        cdsize = msglen + pbit;
        cout << "Code Word Size = " << cdsize << endl;
        return cdsize;
    }

    int *getCdWord()
    {
        reverse(sn.begin(), sn.end());
        for (int i = 0; i < 40; i++)
            arr[i] = 5;

        for (int i = 1, j = 0; i <= cdsize; i++)
        {
            if (pow(2, j) == i)
            {
                j++;
                continue;
            }
            arr[i] = sn[i - j - 1] - 48;
        }

        setParity();
        cout << "Sender's Data: ";
        for (int i = cdsize; i >= 1; i--)
            cout << arr[i] << " ";
        cout << endl;

        return arr;
    }

    void setParity()
    {
        cout << "Enter Parity Type: ";
        cin >> ptype;

        int cnt = 0;
        if (ptype == 'E' || ptype == 'e')
            for (int i = 3; i >= 0; i--)
            {
                for (int j = 1; j <= cdsize; j++)

                    if (map[j][i] == '1' && arr[j] == 1)
                        cnt++;

                int z = pow(2, 3 - i);
                if (cnt & 1)
                    arr[z] = 1;
                else
                    arr[z] = 0;
                cnt = 0;
            }

        else if (ptype == 'O' || ptype == 'o')
            for (int i = 3; i >= 0; i--)
            {
                for (int j = 1; j <= cdsize; j++)
                    if (map[j][i] == '1' && arr[j] == 1)
                        cnt++;

                int z = pow(2, 3 - i);
                if (cnt & 1)
                    arr[z] = 0;
                else
                    arr[z] = 1;
                cnt = 0;
            }
    }
};

class Receiver
{
    string map[30] = {"0000", "0001", "0010", "0011", 
                    "0100", "0101", "0110", "0111", 
                    "1000", "1001", "1010", "1011", 
                    "1100", "1101", "1110", "1111"};
    int *brr,cdsize;

public:
    void recMsg(int brr[],int cdsize)
    {

        this->brr = brr ;
        this->cdsize = cdsize;
        srand(time(0));
        int x = rand() % cdsize + 1;
        x = rand() % cdsize + 1;

        brr[2] = brr[2] ^ 1;
        cout << "Received Data: "; 
        for (int i = cdsize; i >= 1; i--)
            cout << brr[i] << " ";
        cout << endl;
    }

    void err()
    {
        int err[10];
        int cnt=0;
        if (ptype == 'E' || ptype == 'e')
            for (int i = 3; i >= 0; i--)
            {
                for (int j = 1; j <= cdsize; j++)
                    if (map[j][i] == '1' && brr[j] == 1)
                        cnt++;

                int z = 3 - i;
                if (cnt & 1)
                    err[z] = 1;
                else
                    err[z] = 0;
                cnt = 0;
            }

        else if (ptype == 'O' || ptype == 'o')
            for (int i = 3; i >= 0; i--)
            {
                for (int j = 1; j <= cdsize; j++)
                    if (map[j][i] == '1' && brr[j] == 1)
                        cnt++;

                int z = 3 - i;
                if (cnt & 1)
                    err[z] = 0;
                else
                    err[z] = 1;
                cnt = 0;
            }

        int errbit = 0;
        for (int i = 0; i < pbit; i++)
            errbit += err[i] * pow(2, i);

        if (errbit == 0)
            cout << "No ERROR" << endl;

        else
            cout << cdsize - errbit + 1 << " number bit has got error\n";
    }
};

int main()
{
    Sender a;
    Receiver c;
    int msglen, cdsize,*arr, brr[50];

    a.setmsg();
    cdsize = a.getCdSize();
    arr = a.getCdWord();

    for (int i = 0; i < 40; i++)
        brr[i] = arr[i];

    c.recMsg(brr,cdsize);
    c.err();

    return 0;
}