#include "../header.h"

// Brute force
// class Solution {
// public:
//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         vector<vector<string>> res;
//         sort(products.begin(), products.end());
//         string temp = "";
//         for (int i = 0; i < searchWord.length(); ++i) {
//             temp += searchWord[i];
//             vector<string> tv;
//             for (int j = 0; j < products.size(); ++j) {
//                 if (products[j].length() >= temp.length() && products[j].substr(0, temp.size()) == temp) {
//                     tv.push_back(products[j]);
//                     if (tv.size() == 3) {
//                         break;
//                     }
//                 }
//             }
//             res.push_back(tv);
//             if (tv.size() == 0) {
//                 while (res.size() != searchWord.length()) {
//                     res.push_back(tv);
//                 }
//                 return res;
//             }
//         }
//         return res;
//     }
// };

// Trie tree
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        trieNode * head = NULL;
        int n = products.size();
        for (int i = 0; i < n; ++i) {
            if (products[i][0] == searchWord[0]) {
                if (head == NULL) {
                    head = new trieNode();
                }
                addString(head, products[i]);
            }
        }
        for (int i = 0; i < searchWord.length(); ++i) {
            if (head == NULL) {
                result.push_back({});
                continue;
            }
            if (i > 0 && head->m.find(searchWord[i]) != head->m.end()) {
                head = head->m[searchWord[i]];
            }
            else if (i > 0) {
                head = NULL;
                result.push_back({});
                continue;
            }
            vector<string> curret;
            vector<char> temp;
            dfs(head, curret, temp);
            for (int j = 0; j < curret.size(); ++j) {
                curret[j] = searchWord.substr(0, i + 1) + curret[j];
            }
            result.push_back(curret);
        }
        return result;
    }
    
private:
    struct trieNode {
        bool end;
        map<char, trieNode *> m;
        trieNode() {
            end = false;
        }
    };
    
    void addString(trieNode * head, string str) {
        if (head == NULL) {
            return;
        }
        for (int i = 1; i < str.length(); ++i) {
            if (head->m.find(str[i]) == head->m.end()) {
                head->m[str[i]] = new trieNode();
            }
            head = head->m[str[i]];
        }
        head->end = true;
    }
    
    void dfs(trieNode * node, vector<string> & ret, vector<char> & temp) {
        if (ret.size() == 3) {
            return;
        }
        if (node->m.size() == 0) {
            string cur(temp.size(), ' ');
            for (int i = 0; i < temp.size(); ++i) {
                cur[i] = temp[i];
            }
            ret.push_back(cur);
            return;
        }
        if (node->end) {
            string cur(temp.size(), ' ');
            for (int i = 0; i < temp.size(); ++i) {
                cur[i] = temp[i];
            }
            ret.push_back(cur);
        }
        for (auto it = node->m.begin(); it != node->m.end(); ++it) {
            temp.push_back(it->first);
            dfs(it->second, ret, temp);
            temp.pop_back();
            if (ret.size() == 3) {
                return;
            }
        }
    }

    void tempdfs(trieNode * node, vector<char> & tt) {
        if (node->m.size() == 0) {
            for (int i = 0; i < tt.size(); ++i) {
                cout<<tt[i];
            }
            cout<<endl;
            return;
        }
        for (auto it = node->m.begin(); it != node->m.end(); ++it) {
            tt.push_back(it->first);
            tempdfs(it->second, tt);
            tt.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<string> v{"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> vv = s.suggestedProducts(v, "mouse");
    // vector<string> v{"oqjrtcokaagakchrwrdbrlpnqivwcpzwuxbdkpkhndevouwyrtmbokxolhbvrencthmyplqixnhnokbhtbstmslfbinsypubqjckiqujvmknxuomdwqkfudgiqmpzkvnshrmnoeonzyfaipdcfdwhekrazfkdlfluyvoevahsyhvqjfcizxjhucbpqdjgmqqalqnvfyrtfkyrxlavfbagxkdloetaiedqbrmtzxwwrpyewrcbntsnrdzurzlfokcxolkltouozdobqvtoldjuincumspqpujynxxetbflfnkrscxgrvennmczurjvnoalxcfcrnddfckavedjrvewmawxazviumzpudgolofsxllhgsdrnvjbipcsqsdoosfdkhavhicsfbyavwyxziefmycknhzqujqkbqhacuaebwqpkfnkovxchczohhirczixikuoktkaamchcghynclonujiyzkcghjjjtzckjxmpssfqjirnfvrddvoqvdeteegupzevydcywjsoybsflpgpzkcoztcayffscwxkofwibguysdjtmddgevjhbxrfiqliqyiczdunhosdctrvlagcugpsskpvlsdhcbpdtdwjbhchymlptjrmzmezwljxemgzecptluxbwtgoyvqwrvxkartgrebdegyqdibemnficwpgsywlzczvwujmykkyhkkxhvrtmjxcyidawfxjcagsgutndplixpepddiosflfoujxndtgxsbzarlwacjtydorlrtukbyibaktiphojmrcbwjppnuwwihuerqswjpmyblrdslnwpdnzovpslsrfbzhjywbimwdiqhxmdssjovufgbqqykozfjbylihfwanzjdtgeoimwowocykeskvivwuybdrowolstbrbenioagkgwednhymqisdvjuycjvtrurzqssxrisozysizxeoyelhglnppsjzggjunmyabzptlfktzphlmhvpoqlnrwgxauepumssyecjpwfozhxhvodsasomhtgbasijrpphbijnxcyrajypogighdxacjxqyxagfuenwrdajqsuzrjtrqjebjnbmdzbqdgmbuqofbyegnxvgsegbaqxsdjjffdxiqgqtlgclqtmjqfmbrsccnoidkugbwscamrqfqmpbfuvvoxrodoccusixfehzetsbiflonazsmacvwilarpgpwjkexykqkmklqcuhdrhhgrzofbsjvzwdaghqxajgwqmuhyyervscyiyggbqyhpvotnmaubapigegatgtqeazgcytubsuhjzipbyxnkyqveeetgecxwinwdjuawpzdieizlzqplzajafeernecfkpiilnuqdjnipjybqishinomemdxfwabhemxecuyailbogehxwwtzvaueonxkjmdvojpjjxaftvnbbsfcjjyzwartrbmxgktbhrqeynwoziddoh",
    //     "kfnyprlqjosvbkvfvanhqsxpfezfafuzxchbwsdagvgtmtwdjsgnodkahyfkpyfmrbrcineichemlomrgaydmjnzbqxhzpciwkwbcsrpeafwkitjibviipnhvcqntjuwnccylnqdwxmirvnggcdwfbldnhxsjjhfqcxlggcpldamlyttzibadxzcpwecjjxekeoucanprljnsgvhpxjydazzlxofypaxcnwhhkhrtwbecouqvoxnzsitdzyrxokhdtynjgygqarnhyaqsdrgdqdmpfwdhlayltvrjalfxxctwgqtmuwgdwzxyuiictaul",
    //     "kfnwqytfhroyewirkaofdwdjtzyaeamrqkbdzganjfqfykfwizgtxjhrbvnmbwyfivwrbbjralxuptonwhlvztgefnggltqekduxdhznowjsayyaieacjvewhfookivjuwmwmhlobrgummkvjwclbipmkwrpbwqlbthbokenmcaupqbtuglgqtpuognhfachuscdsztjbuffgdzajlzhmnmksdnyrhahnnhilwnqohxyjsiatzshinquevymllusyqzkjwovmgtwwfztpbcpvyjdkqcdkscpimchxdjdrxvropgbgrrccfqnatlqjlojfczeggnanpuqtebjcyezdqpxsfkegxqfeplcmfxyqmlruapeywuftbbosmpegfpcepukcsvpgmfundbvbzazwqnefmbnnxntixtormwfbnuwheahzddwksodogedymeujvxacdbguthxhlcmmblfwjrnurpfuawoghyakqkccxcgxzdraasdivjgvtjrulhgktdxjuzpdyewckrpmjrttusqubhwntpchscprcdddsbyxrqrnplgazwjvojrtxogqdvqarcspvkfljlswpktqxlndidtnhzryohyyujfncunynxkblsdpjlaifdzsjxpuapwjzwzeahrnfkgtaehwjqsligfjnmsivinygzoeaejagsvzkyicbsyfxhqaotexdsvtxuexnmqsjhmojexevbgozlkbmuuexgpklnsetscrceuvtfhrxwvloiucqbzpxwtodopesljmisfxqmxhjlehpyaodfwqbnfvjtplauiyiyrddbjdpkvznmvpbzxgemfhgpwligjwznbztyaenziwooceebfwppfpgmzczoenqtmqcjdgvdlhjpwwlqcyjmaqnjicyrocrvxxrnrhpsqvrndurviilufvwbsswtjlmefydjechqrgeqjucsjyaaudocxgpvtbfekgynmnywltxvqddtjdaunvfqjclrjsohfenjxqjpvcklfdjoaavgoukzqjijycwqipkzpcvaqzqwgwnolrqudrcqqymlhelskpvrlobsjxlgsunkdlvqdgpnnrhcgdxasbdmrcrauswiticdiwkhdvpkduqgqpujcyjkrksmhjswvqccpxfacszfdsdvoxjnlphqawjlxryprgoexjqxryuxadviwdebxjyzolpqerfkxhklgpeffahclnfyfnwudwnjjqbcazsuzekwfsprbiwztqsxtxpiemfucwgcamdowvoymuwkstyqggmtknzezacoklmiaanvsttqknedeoayakomzzzntfmyfaunsnvimvkboqcfprizsofhauflvmetrwfoigjcxjavspnaqwpagfwslxolbjgglknrcacqntfcizfkmcrdbdidvojdritvnvgnsvrhjcutojfvjaspzdodnisyuirklwcxjitakdpxaclthbxgooxmqslftctxopfencxtzktckpkpkhlkboueylshbztlvkbtkpjdcxakldxmnjnqjyscgvydlmnpfnaxaicylivtesvtoqimovynmntiijxnwinlirbmiubpwlmwdscynsywgswsklxaxjwoculminicuphgtepjxmlhaolzzxuqqawjmvlniknniwexrelrvxagbtcqnzhdmiqfkyvwnsfuzskzlcvcyluzjtesuvzdknipreueyqgzvgbeqtmcnzwtfdgmihuzwtsdxahawfiwnpzzwpnzawfzyobyriuxbnlojvkfycwprgngluhgyirhutknuvdyebwrmaarbelkhzoqpilrneitzzuysmlpczdepdngeuwcpylcysafnmzulcrzlkaskbiexjikebbrwlbcpgvmiumsafuzqcuxnpwtjgqmlmnbeauljmyrxykugovjfazsrkzsyonecfejokeiwtxvdjawbkgvlqegxcoxwhldzoblzvhydopqpatwxllccdnlmxjypjiimtczqhubuloozyiwjmcsooqvufuamaopwxsexaaohazzctezrqahkdsnkqspkjqcvocnqirwzxocbxibrwrlrhzcuxlfqsgwoqyagkmcrdedasvrzjgugbrvvbsjtmjfbdxhchbkfomefrfrwdiyhhskrqstnnwrclsphqfrbwjvlitjmwtlmx","kfnyprlqjosvbkvfvanhqsxpfezfafuzxchbwsdagvgtmtwdjsgnodkahyfkpyfmrbrcineichemlomrgaydmjnzbqxhzpciwkwbcsrpeafwkitjibviipnhvcqntjuwnccylnqdwxmirvnggcdwfbldnhxsjjhfqcxlggcpldamlyttzibadxzcpwecjjxekeoucanprljnsgvhpxjydazzlxofypaxcnwhhkhrtwbecouqvoxnzsitdzyuoyzfkyseiohccpdtnjhqlrkgpcifvatradjfurxmwfssmbpbvxeoialjeyxujpgqdunhrthidhizzqddvuqzmoenmjzunulkrjyxfugrpvkwoiwyxwgrweakhbswllbyziranhxkleggegegdailjgyteaghdqnjqdjfhyrapqmckvxgxmasnweej"};
    // vector<vector<string>> vv = s.suggestedProducts(v, "kfnyprlqjosvbkvfvanhqsxpfezfafuzxchbwsdagvgtmtwdjsgnodkahyfkpyfmrbrcineichemlomrgaydmjnzbqxhzpciwkwbcsrpeafwkitjibviipnhvcqntjuwnccylnqdwxmirvnggcdwfbldnhxsjjhfqcxlggcpldamlyttzibadxzcpwecjjxekeoucanprljnsgvhpxjydazzlxofypaxcnwhhkhrtwbecouqvoxnzsitdzyuoyzfkyseiohccpdtnjhqlrkgpcifvatradjfurxmwfssmbpbvxeoialjeyxujpgqdunhrthidhizzqddvuqzmoyrnqunojmtporeofgldjntqvlngobvtpbhmmdrkosxlkvmivonldjr");
    for (int i = 0; i < vv.size(); ++i) {
        cout<<vv[i].size()<<": ";
        for (int j = 0; j < vv[i].size(); ++j) {
            cout<<vv[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}