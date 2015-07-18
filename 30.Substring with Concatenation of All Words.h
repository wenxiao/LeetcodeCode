class Solution {
	//��Ҫ�Ƚϵ�word�ַ����ĳ��ȼ�Ϊlen���ܹ���m�����ʣ�s�ĳ���Ϊn
	//��s��ÿ����len���ַ������hashֵ���ⲽʱ�临�Ӷ�ΪO(n)
	//Ȼ���ǰ����ɨ��һ�Σ�ά��һ��map��һ�γ���Ϊm*len���ַ����У�
	//	ÿ�����ʳ��ֵ�Ƶ���ļ�¼��ÿ�θ��¸��Ӷ�ΪO(log m)�����º���
	//	�����words��hash��¼�Ƚϵ�ƽ�����۽ӽ�O(1)������ΪO(m)
	
	//��������s[i ... j]��hashֵΪ(s[i]*p^(len-1)+s[i+1]*p^(len-2)+...+s[i+len-1])%mod
	//��������s[i+1 ... j+1]��hashֵ��ʱ�򣬿���ֱ���� (hash(s[i...j])*p+s[len]-s[i]*p^len)%mod
public:
    static const int mod=2097593;
    static const int prime=131;
    int erase_value;
	int len;
    int calc_xpown(int x){
        int r=1;
        for(int i=0;i<len;i++)
            r=(r*x)%mod;
        return r;
    }
    int init_hashcode(string s){
        int r=0;
        for(int i=0;i<len;i++){
            r=(r*prime+s[i])%mod;
        }
        return r;
    }
    int update_hashcode(string s, int r, int index){
        return ((r*prime+s[index]-erase_value*s[index-len])%mod+mod)%mod;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        map<int,int> hashcode_to_ct;
		map<int,int> position_to_hashcode;
        vector<int> ret;
        len=words[0].size();

        if(words.size()==0 || words.size()*len>s.size())
            return ret;
        
        erase_value=calc_xpown(prime);
        for(int i=0;i<words.size();i++)
            hashcode_to_ct[init_hashcode(words[i])]++;
            
        int hashcode=init_hashcode(s);

		for(int i=0;i+len-1<s.size();i++){
			position_to_hashcode[i]=hashcode;
			hashcode=update_hashcode(s,hashcode,i+len);
		}

		for(int i=0;i<len;i++){
			map<int,int>hashcode_to_ct_current;
			for(int j=i;j<s.size();j+=len){
				hashcode_to_ct_current[position_to_hashcode[j]]++;
				if(j/len>words.size()-1){
					hashcode_to_ct_current[position_to_hashcode[j-len*words.size()]]--;
				}
				if(j/len>=words.size()-1){
					int has_diff=false;
					for(auto e:hashcode_to_ct)
						if(hashcode_to_ct_current[e.first]!=e.second)
						{
							has_diff=true;
							break;
						}
					if(!has_diff)
						ret.push_back(j-len*(words.size()-1));
				}
			}
		}

		return ret;
    }
};
