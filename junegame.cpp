#include <cstdlib>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include <math.h>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int NUMSTATES = 50;
const int BOARDSIZE = 25;
const int MAXSCORE = 331449281;
// char board[] = "MAODVAINAIWSLRCTEOYHGNWUA";
const string states[NUMSTATES] = {"CALIFORNIA","TEXAS","FLORIDA","NEWYORK","PENNSYLVANIA","ILLINOIS","OHIO","GEORGIA","NORTHCAROLINA","MICHIGAN","NEWJERSEY","VIRGINIA","WASHINGTON","ARIZONA","MASSACHUSETTS","TENNESSEE","INDIANA","MARYLAND","MISSOURI","WISCONSIN","COLORADO","MINNESOTA","SOUTHCAROLINA","ALABAMA","LOUISIANA","KENTUCKY","OREGON","OKLAHOMA","CONNECTICUT","UTAH","IOWA","NEVADA","ARKANSAS","MISSISSIPPI","KANSAS","NEWMEXICO","NEBRASKA","IDAHO","WESTVIRGINIA","HAWAII","NEWHAMPSHIRE","MAINE","RHODEISLAND","MONTANA","DELAWARE","SOUTHDAKOTA","NORTHDAKOTA","ALASKA","VERMONT","WYOMING"};
const int scores[NUMSTATES] = {39538223,29145505,21538187,20201249,13002700,12812508,11799448,10711908,10439388,10077331,9288994,8631393,7705281,7151502,7029917,6910840,6785528,6177224,6154913,5893718,5773714,5706494,5118425,5024279,4657757,4505836,4237256,3959353,3605944,3271616,3190369,3104614,3011524,2961279,2937880,2117522,1961504,1839106,1793716,1455271,1377529,1362359,1097379,1084225,989948,886667,779094,733391,643077,576851};
// const int scoreing2[NUMSTATES] = {0,29145505,21538187,20201249,13002700*100,12812508,11799448,10711908,10439388,10077331*10,9288994,8631393,7705281,7151502*10,7029917*10,6910840,6785528,6177224*10,6154913*10,5893718,5773714*10,5706494*10,5118425,5024279,4657757,4505836,4237256,3959353,3605944,3271616*10,3190369,3104614,3011524,2961279*10,2937880,2117522*10,1961504,1839106,1793716,1455271,1377529,1362359*10,1097379,1084225*10,989948,886667,779094,733391,643077,576851};
// const int scoreing3[NUMSTATES] = {10,5,7,7,12,8,4,7,13,8,9,8,10,7,13,9,7,8,8,9,8,9,13,7,9,8,7,8,11,4,4,6,8,11,6,9,8,5,12,6,12,5,11,7,8,11,11,6,7,7};
const char alphabet[] = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
const int ALPHABETSIZE = 25;
vector<vector<int>> adjlist{
    {1,5,6},
    {0,2,5,6,7},
    {1,3,6,7,8},
    {2,4,7,8,9},
    {3,8,9},
    {0,1,6,10,11},
    {0,1,2,5,7,10,11,12},
    {1,2,3,6,8,11,12,13},
    {2,3,4,7,9,12,13,14},
    {3,4,8,13,14},
    {5,6,11,15,16},
    {5,6,7,10,12,15,16,17},
    {6,7,8,11,13,16,17,18},
    {7,8,9,12,14,17,18,19},
    {8,9,13,18,19},
    {10,11,16,20,21},
    {10,11,12,15,17,20,21,22},
    {11,12,13,16,18,21,22,23},
    {12,13,14,17,19,22,23,24},
    {13,14,18,23,24},
    {15,16,21},
    {15,16,17,20,22},
    {16,17,18,21,23},
    {17,18,19,22,24},
    {18,19,23}
};

string s1 = "GTAIVENRCHWOISIYLANMFRDCA"; // 220.693 .665841
string s2 = "MAODVAINAIWSLRCTEOKHGNYUA"; //224.674 .65344 
string s3 = "JWYAHTEROCPNILNNSAVFACYNO"; //.677852
string s3_1 = "JWYADTEROISNIGLOSALFMCIMC"; //238.481 .719509
string s4 = "JOTAWWENGHYARICMOLADCNISN"; // 255.254 .770114
string s5 = "KCMIAIAIEWNLGTAIRONSVDAIW"; // M8 207 .624
string s5_1 = "NWASWNETNIMIGOACALRDDINKI"; // 233.921
string s6 = "TASOTWENGHYSRICCOLADENISN"; // 232.292 .700838
string s6_1 = "TWYSNSESOIANRLMUGIAOTHCDN"; // 250.986 85000/10000
string s6_1_1 = "MOTAWWENGHJYRICIOLADCNISN"; // 251.357 40000/5000
string s7 = "QTNMPYEAICLRSSHNAUOQCHTQQ"; //90
string s7_1 = "WDLCMAIOAKGRNRTONSEYLIALW"; // 232.882 4000/22000
string s9_0 = "UGRHTCHSEWSANIYDIROVIGLAC"; //226.335
string s9 = "CALGSGORIDYINAHWESCMZTRUI"; // 244.219
string s9_1 = "GALGSCORIDYINAHWESCMMTRUI";
string s9_2 = "CALGSVORIDYINAHWESCMTROUI";
string s911 = "CALGSMORIDYINAHWESTCTVROU"; //248.937
string s9_3 = "ACUGILORIDYINAHWESTCTROIM"; //258.714 .780554
string s9_2_1 = "TWYMCREIOAOSNRLMTAIGICHDS"; //256.705 5000/15000
string s9_3_1 = "JWYLCSEIOAESNRMOTAIGIHCDS"; //259.379
string s11 = "GTAIVENRSEWOIDNYLACHDNOMI"; //200
string s11_1 = "GTAIVENRSDWOINAKLAMHEROCI"; //232.664
string s12 = "PWYLQTESOVHRNARCAOIGLIDQQ"; //207.098
string s12_1 = "MCNORAIHTWNLGAEKRONSIDAIW"; //243.381, 6500/50000
string s13 = "PWYLFTESOVHRNARCAOIGMTLCS";
string s13_1 = "FLYWPVOSEURANRTGIOAISMLCM"; // 4500/53000
string s14 = "QHCMPQUAIEMNSSNIAYOUULRQQ"; //for awards
string s14_1 = "MVDORLANIGROSAHISTIPENNEM"; //4000/43000
string s15 = "QHCMPTUAIEAOSSNMRNETYLADQ"; //76 PA & M8
string s15_1 = "PINUEHEANTCISOAOMSYLLRARI"; //32500/55050
string s16 = "CALIFORNIANEWYORKCAROLINA"; 
string s16_1 = "FLARNICOIGMNSNALAOEWCHTRK"; //236.472 38500/163000
string s16_2_1 = "HSNMKGIAORCRWETOLNAHFILDC"; //238.421 3000/12000
string s16_3_1 = "CAIGKRNSRYOITEOCLWANFAHOM"; //237.536 5000/15000
string s16_4_1 = "NYWMCOTEADMRSNLICOIAGLFRG"; //233.824 5000/7000
string s17 = "TEGYWHROSECALNRSEIOAQRGSC"; //172 
string s18 = "TRSAQHEOWICIYNEDAROQNILQQ"; //164 
string s19 = "ANUMHSOGICLIRADAONETCQYWJ"; //204
string s20 = "LACHMIORIDSNYGAAEWQQQJTQQ";
string s21 = "CVIREFATGOLONEJSIRWYHCAKQ";
string s21_1 = "DASNPVINEWLORSYMACOAOHTEG";
string s22 = "CSAMAIONOYLIREWDAGTJNCHIM";
string s23 = "DASGTWINEJLOROWNACUYTMIHT";
string s24 = "JWYGEKETHONRCARIAOSGDLINA";
string s25 = "MHTWPCAYEJLORNAVINETDASOE";
string s25_1 = "MHIQPCAKGELORNAVINEYDASWJ";
string s26 = "WUOYWFIREOLCNSTAOIAHHMRGC";
// "DASNP"
// "VINEW"
// "LORSY"
// "MACOA"
// "OHTEG"

int max_all_score = -1;
int max_gen = 0;
string max_all_board;


int test_basic_string(string& board, string state, int index){
    // is there an "indiana" next to any squares next to index?
    if(state.size()==0){
        return 1;
    }
    vector<int> adj = adjlist[index];

    for(int i=0; i<adj.size(); i++){
        if(board[adj[i]]==state[0]){
            if(test_basic_string(board, state.substr(1),adj[i])){
                return 1;
            }
        }
    }
    return 0;
}

int test_skip_string(string& board, string state, int index){
    //is there a "california" starting at index square with a skip available?
    if(state.size()==0){
        return 1;
    }
    vector<int> adj = adjlist[index];

    if(test_basic_string(board, state.substr(1), index)){
        return 1;
    }
    if(board[index] == state[0]){
        for(int i=0; i<adj.size(); i++){
            if(test_skip_string(board, state.substr(1), adj[i])){
                return 1;
            }
        }
    }
    
    return 0;
}

int test_string(string& board, string state){
    for(int i=0; i<BOARDSIZE; i++){
        if(test_skip_string(board, state, i)){
            return 1;
        }
    }
    return 0;
}

const int MEMOSIZE = 1000;
string memo[MEMOSIZE];
int memo_score[MEMOSIZE];
double memo_value[MEMOSIZE] = {};

int score(string& board, int verbose = 0){
    if(board == s4){
        return 255253829;
    }
    else{
        int score[NUMSTATES];
        for(int i=0; i<BOARDSIZE; i++){
            score[i] = 0;
        }

        int total_score = 0;
        for(int i=0; i<NUMSTATES; i++){
            string state = states[i];
            score[i] = test_string(board, state);
            total_score += score[i]*scores[i];
            if(verbose){
                cout << state << '\n';
                cout << score[i] << '\n';
            }
        }

        return total_score;
    }
}

int memoScore(int gen, string& board, int verbose = 0, int calculatemax = 0){
    int result = -1;

    for(int i=0; i<MEMOSIZE; i++){
        // if(verbose){
        //     cout << memo_value[i] << " ";
        // }
        if(memo_value[i]<=0.001){
            memo_value[i] = 3;
            memo_score[i] = score(board);
            memo[i] = board;
            result = memo_score[i];
            break;
        }
        else if(memo[i]==board){
            memo_value[i]++;
            result = memo_score[i];
            break;
        }
        else{
            memo_value[i]/=1.001;
        }
    }
    if(result==-1){
        result = score(board, 0);
    }
    
    if(calculatemax){
        if(result > max_all_score){
            max_gen = gen;
            max_all_board = board;
            max_all_score = result;
        }
    }
    return result;
}

const int N = 1000;
double base_adj_p = 0.015;
double base_point_p = 0.03;
double base_rot_p = 0.001;
double base_refl_p = 0.0001;
const double recursive_mutation_rate = 0.75;
const int G = 10000000;
const int S = 20;

string boards[N]; //boards (population)
vector<int> ids; //scores of the text file. if we ever get this score, we abort.

void print_board(string& board){ 
    for(int i=0; i<BOARDSIZE; i++){
        cout << board[i] << " ";
        if(i%5==4){
            cout << '\n';
        }
    }
    cout << board;
    cout << '\n';
}

void print_max_score(int gen, int check_all_max = 0){ // (max_score, max_index) of current boards[][]
    // int max_score = -1;
    // int max_index = -1;
    // for(int i=0; i<N; i++){
    //     int boardscore = score(boards[i]);
    //     if(boardscore > max_score){
    //         max_score = boardscore;
    //         max_index = i;
    //     }
    // }
    cout << (double)max_all_score/1000000 << '\n';
    print_board(max_all_board);
    // if(check_all_max){
    //     if(max_score>max_all_score){
    //         max_all_score = max_score;
    //         max_all_board = boards[max_index];
    //         max_gen = gen;
    //     }
    // }
}

//initializes random boards according to alphabet
void init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<BOARDSIZE; j++){
            boards[i][j] = alphabet[rand() % ALPHABETSIZE];
            // cout << boards[i][j] << '\n';
        }
    }
}

void init_special(){
    char str1[] = "MAODVAINAIWSLRCTEOYHGNWUA";
    char str2[] = "JWYAHTEROCPNILNNSAVFACYNO";
    for(int i=0; i<N/2; i++){
        for(int j=0; j<BOARDSIZE; j++){
            boards[i][j] = str1[j];
        }
    }
    for(int i=N/2; i<N; i++){
        for(int j=0; j<BOARDSIZE; j++){
            boards[i][j] = str2[j];
        }
    }
}

void init_special2(){
    string str1 = s26;
    string str2 = s26;
    string str3 = s26;
    string str4 = s26;
    for(int i=0; i<N/4; i++){
        boards[i] = str1;
    }
    for(int i=N/4; i<N/2; i++){
        boards[i] = str2;
    }
    for(int i=N/2; i<3*N/4; i++){
        boards[i] = str3;
    }
    for(int i=3*N/4; i<N; i++){
        boards[i] = str4;
    }
}

double fitness1(int score){
    return ((double)score/MAXSCORE);
}

double fitness2(int score){
    return pow(((double)score/MAXSCORE),1);
}

int* parentsRoulette(double* fitness){ //roulette selection: probability of selecting is fitness/total fitness
    double total_fitness = 0;
    for(int i=0; i<N; i++){
        total_fitness+=fitness[i];
    }

    vector<int> unselected = {}; //unselected indices
    for(int i=0; i<N; i++){
        unselected.push_back(i);
    }

    int* parents = new int[N/2];
    for(int i=0; i<N/2; i++){
        double r = (((double)rand()) / RAND_MAX)*total_fitness;
        int j=0;
        while(r>0){
            r-=fitness[unselected[j]];
            j++;
        }
        parents[i] = unselected[j-1];
        unselected.erase(unselected.begin()+j-1);
        total_fitness-=fitness[unselected[j-1]];
    }
    return parents;
}

template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

int* parentsTop50(double* fitness){
    int* parents = new int[N/2];

    vector<double> copy;
    for(int i=0; i<N; i++){
        copy.push_back(fitness[i]);
        // cout << i << ' ' << fitness[i] << '\n';
    }
    // cout << 'done' << '\n';

    int count = 0;
    for(auto i: sort_indexes(copy)){
        if(count>=N/2){
            parents[count-N/2] = i;
            // cout << i << ' ';
        }
        count++;
    }

    return parents;
}

vector<double> avg_fitness;

int stepTop(double k /*percent to kill, i.e. bottom 10% kill*/, vector<double>& fitness, int mode, int verbose = 0){
    int K = k * N;
    int* parents = new int[K];

    vector<size_t> sorted = sort_indexes(fitness);

    if(verbose){
        double total_fitness = 0;
        for(int i=0; i<N; i++){
            cout << fitness[sorted[i]] << " ";
            total_fitness += fitness[i];
        }
        avg_fitness.push_back(total_fitness/N);
        cout << '\n';
        // for(int i=0; i<N; i++){
        //     cout << sorted[i] << " ";
        // }
        // cout << '\n';
        for(int i=0; i<avg_fitness.size(); i++){
            cout << avg_fitness[i] << " ";
        }
        cout << '\n';
    }

    if(mode==0){
        for(int i=0; i<K; i+=2){
            int indices[] = {sorted[i], sorted[i+1]}; // indices that are killed
            int par1 = sorted[(K+rand()%(N-K))];
            int par2 = sorted[(K+rand()%(N-K))];
            int parents[] = {par1, par2};// random that is not killed 

            int parenttoduplicate = rand()%2;
            boards[indices[0]] = boards[parents[parenttoduplicate]];

            // cout << "testing" << '\n';
            int r = rand()%BOARDSIZE; // number of letters from first parent
            int start = rand()%BOARDSIZE; // starting index to replace
            // cout << "test";
            // cout << start << " ";
            int filled[BOARDSIZE] = {}; // 1 if filled 0 if not
            int count = 0;
            while(count < r){
                if(filled[start]!=1){
                    filled[start] = 1;
                    indices[count] = start; 
                    count++;
                    // cout << start << " ";
                }
                vector<int> adj = adjlist[start]; 
                start = adj[rand()%adj.size()];
            }

            string newstr = "";
            for(int j=0; j<BOARDSIZE; j++){
                if(filled[j]){
                    newstr+=boards[par1][j];
                }
                else{
                    newstr+=boards[par2][j];
                }
            }
            
            boards[indices[1]] = newstr; // copy the random board into killed board
        } 
    }
    if(mode==1){
        for(int i=0; i<K; i++){
            int index = sorted[i]; // index that is killed
            parents[i] = sorted[(K+rand()%(N-K))]; // random that is not killed 
            boards[index] = boards[parents[i]]; // copy the random board into killed board
        }
    }

    return sorted[N-1];
}

void parentCross(int* parents){ // directly modifies board. no output.
    char nextgen[N][BOARDSIZE];

    //mating process
    for(int i=0; i<N/4; i++){
        int parent1 = parents[2*i];
        int parent2 = parents[2*i+1];

        //create 4 offspring
        for(int j=0; j<4; j++){
            for(int k=0; k<BOARDSIZE; k++){
                char value;
                if(rand()%2==0){
                    value = boards[parent1][k];
                }
                else{
                    value = boards[parent2][k];
                }
                nextgen[4*i+j][k] = value;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<BOARDSIZE; j++){
            boards[i][j] = nextgen[i][j];
        }
    }
}

// void noCross(int* parents){
//     char* nextgen[N];

//     for(int i=0; i<N/4; i++){
//         int parent1 = parents[2*i];
//         int parent2 = parents[2*i+1];

//         //create 4 offspring
//         for(int j=0; j<4; j++){
//             if(j<2){
//                 double r = ((double)rand()) / RAND_MAX;
//                 nextgen[4*i+j] = boards[parent1];
//             }
//             else{
//                 double r = ((double)rand()) / RAND_MAX;
//                 nextgen[4*i+j] = boards[parent2];
//             }
//         }
//     }
    
//     for(int i=0; i<N; i++){
//         for(int j=0; j<BOARDSIZE; j++){
//             boards[i][j] = nextgen[i][j];
//         }
//     }
// }

void mutate_adj(int index){ //returns mutated version of board at index
    int grid_index = rand() % BOARDSIZE;
    vector<int> adj = adjlist[grid_index];
    int grid_index2 = adj[rand() % adj.size()];

    char temp = boards[index][grid_index];
    char temp2 = boards[index][grid_index2];
    boards[index][grid_index2] = temp;
    boards[index][grid_index] = temp2;
}

void mutate_point(int index){
    int grid_index = rand() % BOARDSIZE;
    char letter = alphabet[rand() % ALPHABETSIZE];
    boards[index][grid_index] = letter;
}

void mutate_rotation(int index){
    string copy = boards[index];
    int rotlist[] = 
    {20, 15, 10, 5, 0,
    21, 16, 11, 6, 1,
    22, 17, 12, 7, 2,
    23, 18, 13, 8, 3,
    24, 19, 14, 9, 4};
    for(int i=0; i<BOARDSIZE; i++){
        boards[index][i] = copy[rotlist[i]];
    }
}

void mutate_reflection(int index){
    string copy = boards[index];
    int refllist[] = 
    {20, 21, 22, 23, 24,
    15, 16, 17, 18, 19,
    10, 11, 12, 13, 14,
    5, 6, 7, 8, 9,
    0, 1, 2, 3, 4};
    for(int i=0; i<BOARDSIZE; i++){
        boards[index][i] = copy[refllist[i]];
    }
}

void generation_step(int gen, int mode, double adj_p, double point_p, double rot_p, double refl_p, int verbose = 0){

    // double* fitness = new double[N];
    // for(int i=0; i<N; i++){
    //     int boardscore = score(boards[i]);
    //     fitness[i] = fitness2(boardscore);
    // }

    vector<double> fitness;
    for(int i=0; i<N; i++){
        int boardscore = memoScore(gen, boards[i], 0, 1);
        fitness.push_back(fitness1(boardscore));
    }

    // int* parents = parentsRoulette(fitness);

    // parentCross(parents);

    double factor = gen/(max_gen+1);
    if(factor>5){
        factor = 5;
    }
    if(factor<1||gen<400){
        factor = 1;
    }
    double factor2 = ((double)gen)/(max_gen+1.0);
    if(factor2>10){
        factor2 = 10;
    }
    int maxindex = stepTop(factor*(0.080+0.002*factor2), fitness, mode, verbose); //when using this have a lower mutation rate

    for(int i=0; i<N; i++){
        if(i==maxindex){ //dont mutate max score
            continue;
        }
        double thing = 1;
        while(1){
            double r = ((double)rand()) / RAND_MAX;
            if(r<adj_p*thing){
                mutate_adj(i);
                thing = recursive_mutation_rate/(adj_p+point_p+rot_p+refl_p);
            }
            else if(r<(adj_p+point_p)*thing){
                mutate_point(i);
                thing = recursive_mutation_rate/(adj_p+point_p+rot_p+refl_p);
            }
            else if(r<(adj_p+point_p+rot_p)*thing){
                mutate_rotation(i);
                thing = recursive_mutation_rate/(adj_p+point_p+rot_p+refl_p);
            }
            else if(r<(adj_p+point_p+rot_p+refl_p)*thing){
                mutate_reflection(i);
                thing = recursive_mutation_rate/(adj_p+point_p+rot_p+refl_p);
            }
            else{
                break;
            } 
        }
    }
}

void testrand(){
    init();
}

// "UORTHCHSEWSANIYDIROMAGLAC" 240.921
// "IDSCUGIAHOLRNSRAOIETBCYWT" 240.715

int checkids(){
    for(int i=0; i<ids.size(); i++){
        if(max_all_score==ids[i]){
            return 1;
        }
    }
    return 0;
}

int bound = 4000;
int testgenetic(){
    init_special2();
    time_t prev = 0;
    int mode = 0;
    for(int i=1; i<G; i++){
        if(i>=bound){
            if(i/max_gen >= 3){ 
                return i;
            }
            if(i-max_gen>=100000){
                return i;
            }
            if(i%1000==0){
                if(checkids()){
                    return i;
                }
            }
        }

        double factor = i/(max_gen+1);
        if(factor>10){
            factor = 10;
        }
        if(factor<1||i<400){
            factor = 1;
        }
        generation_step(i, mode, factor*base_adj_p, factor*base_point_p, factor*base_rot_p, factor*base_refl_p, i%500==0);
        if(i%1000==0){
            for(int i=0; i<MEMOSIZE; i++){
                cout << memo_value[i] << " ";
            }

            cout << i << '\n';
            print_max_score(i, 1);
            cout << "MAX ALL-TIME SCORE AND BOARD IS AT GEN ";
            cout <<  max_gen << '\n';
            cout << "SCORE: ";
            cout << max_all_score << '\n';
            cout << "BOARD: ";
            cout << max_all_board << '\n';

            time_t now = time(0);
            cout << "time: \n";
            cout << now-prev << '\n';
            prev = now; 
        }
        else if(i%50==0){  
            cout << i << '\n';
            print_max_score(i); 
        }

        if(i%1==0&&mode==0){
            // if(mode){
            //     adj_p*=2;
            //     point_p*=2;
            // }
            // else{
            //     adj_p/=2;
            //     point_p/=2;
            // }
            mode=(mode+1)%2;
            // cout << "mode: " << mode << '\n';
        }
        else if(i%1==0&&mode==1){
            mode=(mode+1)%2;
            // cout << "mode: " << mode << '\n';
        } 
    }
}

void init_ids(string input_file_name){
    ids.clear();
    std::ifstream myfile;
    myfile.open(input_file_name);
    string myline;
    if(myfile.is_open()){
        while(myfile){
            getline(myfile, myline);
            std::string::const_iterator it = myline.begin();
            while(it!=myline.end() && std::isdigit(*it)) ++it;
            int isnum = (!myline.empty() && it == myline.end());
            if(isnum){
                // cout << stoi(myline) << '\n';
                ids.push_back(stoi(myline));
            }
        }
    }
}
 
// score memoization
// deleting unused structures
// guarantee top board
// parent cross

main (void)
{
    int total = 0;
    for(int i=0; i<NUMSTATES; i++){
        total+=scores[i];
    }
    cout << total << '\n';

    string output_file_name = "s26.txt";
    std::ofstream outputFile(output_file_name, std::ios_base::app);
    outputFile << "Hello 2 da world!\n"; // write data to the file
    outputFile.close();

    string board = s15;
    srand(time(0));
    cout << score(board, 1);

    while(1){
        max_gen = 0;
        max_all_score = -1;
        max_all_board = "";

        std::ofstream outputFile(output_file_name, std::ios_base::app);
        outputFile << "test\n";

        init_ids(output_file_name);

        int stop_gen = testgenetic();
        outputFile << max_all_score << '\n';
        outputFile << max_all_board << '\n';
        outputFile << "maxed at gen: " << max_gen << '\n';
        outputFile << "stopped at gen: " << stop_gen << '\n';
        outputFile.close();
    }
}