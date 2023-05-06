#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int fault_counter = 0;
int main()
{
    int buf_size = 0;
    string input;
    cin >> input;
    buf_size = stoi(input);
    // cout<<buf_size+10<<endl;
    cin >> input;
    // cout<<input<<endl;
    string replacement = input;
    vector<int> page_stream;

    while (true)
    {
        cin >> input;
        if (stoi(input) == -1)
        {
            break;
        }
        page_stream.push_back(stoi(input));
    }

    //  int placement
    if (replacement == "CLOCK")
    {

        cout << "Replacement Policy = CLOCK" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Page   Content of Frames" << endl;
        cout << "----   -----------------" << endl;
        int ptr = 0; //pointer to first element
        int temp;
        vector<int> buf;
        vector<bool> used;
        // reverse(page_stream.begin(), page_stream.end());

        // reverse(page_stream.begin(),page_stream.end());
        int i = 0;
        int current_buf_size = 0;
        int j = page_stream.size();
        for (i; i < j; i++)
        {
            if (current_buf_size < buf_size || (find(buf.begin(), buf.end(), page_stream.at(i)) != buf.end()))
            {
                temp = page_stream.at(i);
                printf("%02d", temp);
                // cout<<std::setfill('0')<<std::setw(2)<<temp;

                // page_stream.pop_back();
                if (!(find(buf.begin(), buf.end(), temp) != buf.end()))
                {
                    buf.push_back(temp);
                    used.push_back(true);
                    current_buf_size++;
                    ptr = (ptr + 1) % buf_size; //ptr does not change responsibility of operating system if element is already present
                }
                else
                {
                    int k = (find(buf.begin(), buf.end(), temp) != buf.end());
                    used.at(k) = true;
                }
                cout << "     ";

                for (int z = 0; z < current_buf_size; z++)
                {
                    printf("%02d ", buf.at(z));

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                cout << "\n";
            }
            else
            {
                fault_counter++;
                // cout << "pageFault" << page_stream.back() << endl; //page at whichfault occured
                while (true)
                {
                    if (!used.at(ptr))
                    {
                        buf.at(ptr) = page_stream.at(i);
                        printf("%02d ", page_stream.at(i));
                        printf("F");
                        // cout<<std::setfill('0')<<std::setw(2)<<page_stream.back()<<" "<<"F";
                        // page_stream.pop_back();
                        ptr = (ptr + 1) % buf_size;
                        break;
                    }
                    else
                    {
                        used.at(ptr) = false;
                        ptr = (ptr + 1) % buf_size;
                    }
                }
                printf("   ");
                for (int z = 0; z < current_buf_size; z++)
                {
                    printf("%02d ", buf.at(z));

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                // cout << " ";
                cout << "\n";
            }
        }
    }
    else if (replacement == "FIFO")
    {
        cout << "Replacement Policy = FIFO" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Page   Content of Frames" << endl;
        cout << "----   -----------------" << endl;
        int temp;
        int ptr = 0;
        vector<int> buf;
        // reverse(page_stream.begin(), page_stream.end());
        // int fault_counter = 0;
        int i = 0;
        int j = page_stream.size();
        int current_buf_size = 0;
        for (i; i < j; i++)
        {
            if (buf_size > current_buf_size || (find(buf.begin(), buf.end(), page_stream.at(i)) != buf.end()))
            {
                temp = page_stream.at(i);
                printf("%02d", temp);

                // page_stream.pop_back();
                if (!(find(buf.begin(), buf.end(), temp) != buf.end()))
                {
                    buf.push_back(temp);
                    current_buf_size++;
                    ptr = (ptr + 1) % buf_size;
                }
                cout << "     ";
                for (int x = 0; x < current_buf_size; x++)
                {

                    printf("%02d ", buf.at(x));

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                cout << "\n";
            }
            else
            {
                fault_counter++;
                // cout<<fault_counter<<endl;
                printf("%02d ", page_stream.at(i));
                printf("F");
                // cout << "pageFault" << page_stream.back() << endl; //page at whichfault occured
                // buf.pop_back();
                // buf.insert(buf.begin(), page_stream.back());
                // page_stream.pop_back();
                buf.at(ptr) = page_stream.at(i);
                ptr = (ptr + 1) % buf_size;
                printf("   ");
                for (int x = 0; x < current_buf_size; x++)
                {

                    printf("%02d ", buf.at(x));

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                // cout<<" ";

                cout << "\n";
            }
            // cout<<fault_counter<<endl;
        }
    }
    else if (replacement == "LRU")
    {
        cout << "Replacement Policy = LRU" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Page   Content of Frames" << endl;
        cout << "----   -----------------" << endl;
        // vector<int> page_stream{2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
        int ptr = 0; //pointer to first element
        int buf_size = 3;
        int temp;
        vector<int> buf;
        // int fault_counter = 0;
        int i = 0;
        int current_buf_size = 0;
        int j = page_stream.size();
        for (i; i < j; i++)
        {
            if (current_buf_size < buf_size || (find(buf.begin(), buf.end(), page_stream.at(i)) != buf.end()))
            {
                temp = page_stream.at(i);
                printf("%02d", temp);
                if (!(find(buf.begin(), buf.end(), temp) != buf.end()))
                {
                    buf.push_back(temp);
                    current_buf_size++;
                }
                cout << "     ";
                for (auto x : buf)
                {
                    printf("%02d ", x);

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                cout << "\n";
            }
            else
            {
                fault_counter++;
                // cout << "pageFault" << page_stream.at(i) << endl; //page at whichfault occured
                temp = page_stream.at(i);
                printf("%02d F", temp);

                // page_stream.pop_back();
                // int current_index=(find(page_stream.begin()+i, page_stream.end(),temp) != current_index-1);
                vector<int> distance;
                int count = i;
                for (int n = 0; n < buf_size; n++)
                {
                    int page = buf.at(n);
                    int distance1 = 0;
                    bool flag = false;
                    int c1 = 1;
                    while (count - c1 != 0)
                    {
                        if (page == page_stream.at(count - c1))
                        {
                            distance.push_back(distance1);
                            flag = true;
                            break;
                        }
                        else
                        {
                            distance1++;
                            c1++;
                        }
                    }
                    if (!flag)
                        distance.push_back(distance1);
                }
                int maxElementIndex = std::max_element(distance.begin(), distance.end()) - distance.begin();
                buf.at(maxElementIndex) = temp;
                printf("  ");
                for (auto x : buf)
                {
                    printf(" %02d", x);
                }
                cout << " ";
                cout << "\n";
            }
        }
    }

    else if (replacement == "OPTIMAL")
    {
        cout << "Replacement Policy = OPTIMAL" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Page   Content of Frames" << endl;
        cout << "----   -----------------" << endl;
        // vector<int> page_stream{2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
        int ptr = 0; //pointer to first element
        int buf_size = 3;
        int temp;
        vector<int> buf;
        // int fault_counter = 0;
        int i = 0;
        int current_buf_size = 0;
        int j = page_stream.size();
        for (i; i < j; i++)
        {
            if (current_buf_size < buf_size || (find(buf.begin(), buf.end(), page_stream.at(i)) != buf.end()))
            {
                temp = page_stream.at(i);
                printf("%02d", temp);
                if (!(find(buf.begin(), buf.end(), temp) != buf.end()))
                {
                    buf.push_back(temp);
                    current_buf_size++;
                }

                cout << "     ";
                for (auto x : buf)
                {
                    printf("%02d ", x);

                    // cout<<std::setfill('0')<<std::setw(2)<<x+" ";
                }
                cout << "\n";
            }
            else
            {
                fault_counter++;
                // cout << "pageFault" << page_stream.at(i) << endl; //page at whichfault occured
                temp = page_stream.at(i);
                printf("%02d F ", temp);

                // page_stream.pop_back();
                // int current_index=(find(page_stream.begin()+i, page_stream.end(),temp) != current_index-1);
                vector<int> distance;
                int count = i;
                for (int n = 0; n < buf_size; n++)
                {
                    int page = buf.at(n);
                    int distance1 = 0;
                    bool flag = false;
                    int c1 = 1;
                    while (count + c1 < j)
                    {
                        if (page == page_stream.at(count + c1))
                        {
                            distance.push_back(distance1);
                            flag = true;
                            break;
                        }
                        else
                        {
                            distance1++;
                            c1++;
                        }
                    }
                    if (!flag)
                        distance.push_back(9999999);
                }
                int maxElementIndex = std::max_element(distance.begin(), distance.end()) - distance.begin();
                buf.at(maxElementIndex) = temp;

                printf("  ");
                for (auto x : buf)
                {
                    printf(" %02d", x);
                }
                cout << " ";
                cout << "\n";
            }
        }
    }
    // cout<<fault_counter;

    cout << "-------------------------------------" << endl;
    cout << "Number of page faults = " << fault_counter << endl;

    return 0;
}