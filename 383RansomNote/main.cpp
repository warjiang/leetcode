#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        const int N = 127;
        int* rArr = (int *) malloc(N * sizeof(int));
        int* mArr = (int *) malloc(N * sizeof(int));
        //memset(rArr,0,N);
        //memset(mArr,0,N);
        for(int i = 'a';i<='z';i++){
            rArr[i] = mArr[i] = 0;
        }
        for(int i = 0;i<ransomNote.length();i++){
            rArr[ransomNote[i]]++;
        }
        for(int i = 0;i<magazine.length();i++){
            mArr[magazine[i]]++;
        }
        //for(int i ='a';i<N;i++){
        //    cout << rArr[i] << " ";
        //}
        //cout << endl;
        //for(int i ='a';i<N;i++){
        //    cout << mArr[i] << " ";
        //}
        //cout << endl;
        bool flag = true;
        for(int i = 'a';i<='z';i++){
            //cout << (char)i << " " << rArr[i] <<" "<< mArr[i] <<endl;
            if(rArr[i] >0 && rArr[i] > mArr[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution s = Solution();

    string str1 = "cibdccdjhgihcdchibjfhhcafebfcdbjhfiebceeihfifbbecajfidfcfceghaddcjgcaajahbdcddebgafieehchgcigdggibjcajabbaghffgijjejcafajafagegfgihahjgajhhdfehgfgagedjbdcgdciiijciiceahbgbdfcifdadhgieiaadcjgifaaefcacgiaifiahidhchficddgaaaigdbbafabeciedcihbfefidfihcehfeihacbbjiffadbiiacjdidbfahehiicchecgjbbfdeaieafbdbhfigbihjiehjhjicbeaicbeeeefcgbihjajahjhfbddecijhhafdgbfbhicfdijecgchbcdccgajjbadfddjdbdaebehejdhjabecjgffafjbdcidhafchheefhjfciafiaffgbifgddeajfdeacgjfaaeahgaacefafcdadhaabajbdieahajfficfedhieaahdbhhbfgcicbbifbieeiheihgbebggfidfiggeaejgfgbbdjgchihibjghfceabcdjafabhceghegadgfcgeieigdjacbcecfgfhebidfajeifbgejfhhbajhidadgjfbcfgfdehcfgdbhhafgfbghfebfeccddbgebaeeghaccjiiiicgiibjfeacdbdfbahfefabgbaibbfgjcaccjjcggdidhajffacgdghcia";
    string str2 = "icfedgijgahgbgiejjhidhdbiffbidaijcbceaihjagibhihjejbfehieeeafegdgabffacejifaddjgjejjebihddcjfgafffbffcgjggiaaicjabgjbbcdgiigfbbedbhdidbdfbfgecddcggheidhdhiiiijcjeibhdjhhiidcafibggbdjcfjbcdbafgifcefhdieibahhiiahcehbbfieihffdjffaefahjedefegahdcffaaigcddbaajafihfaaidijficdbghefdjjjaihhbhbfejhfgiiejcdahgiddjjgdjgebdbhigjdadfadibeafaaadaaaaaacdbbcbfjcbcjbgaadidigcabggigcfefbebciaeejffhiihfijgjdiejgibhehjghhacijbiaffggbfcefedagjeafhgehcajjefeghhhgeefagfabadfdheigdhchgdfcbhacdjafhddgeigccjgifdjcggjebcjhcgggbeiajbhfigcfehafabheedjjhddjieehbfebbagjhffjjjjbehajjcihbaghghicbchgbefhefagcfiacbbeebfjejjiadgaeaccbbediegbfcdifgcagiggfiafgcachhiigbjibdbjabicjihjdajhhahffcighiafhjacbghbccibcafabhbfcbcbicjfgfhcedfbjjigiajbdcjcifadeigghigcghejcaicefejdheefbfccfgbicdabcciegfccjhgeehjgfffdbfdedgefdjgbefgdheaacejeebbfecifjdcfjbjddhdjacfcedhjfdjffggaaigfbdefhhhjgiicefehehaahddddgcejfhfeggiiifacgeheejehbajfjjdhfiiiffbebfcgccgafdehgdbcaefhagaejjhhcghhcdgcifafhbcdhecafhjeebcggadffabfffecaiifahdebhjgjadgbfaehigfdcjideabgghfedcceicbbefdgbdcjgcdedbbehbiheadhcgddhjhahgjbbbaedfbifhhchcdhdbhbhddfaihdahcccgeejbhffjegjbgfghdgbeiiegfgefgecdiefebcbjhecaaechbabfigheffefaiefgcjaaafaiiagjbedihidfjjfhhjjgeaiichbijahfbadichdijcfaejdbcgbbhjbfciajbbgegfdheedifiahbhadgiieagjdhhcegieffigbajgbieicgghbibjdaedagegbfaaggabeebefbhhdahhficgadedifjecabcefgfgabdegdfgaajdbfejiejdcbajdfbhedabbggcfbadibdabiacbbfjhcbjfdjeaeiedjjbbiagadjeecgiiifcffiajchcccbbabfecegibajhjccbiadhfieihfchebebjhhgecddhjfjajjejcehajbcdhgjecbfdfhjiaijchfefgfbjfjgfadebagdbggbaeicehjcghhgfbibfcjbbfigfebgjcafgfhdjfceiaddbeeejecgjhigfahigjcjjfdcjhiddfjcgfeijicjijfgbcfehgiddbibgeadbfabjjegciechaeddbfaaibahggchfhaejjedcjachbgaccijacgbddbgjibabbiidjbdeehgeidfeabbcdejgficcjdaecgcggiihaciedihdihaiiejagejaggddiaccihbcfdegcggghgdaacfigjbjdcfcaeihaaiffbjhjfcabcgbdchfejjachhfighjbbjhifdiigabffjdaedijeifbgdfceagehcacahgdiecabddifdajchjgebjaihbdeibbjffieefagchcdeabbdfdgdjbagjihebaihehjdheheiicjhaehhfhcdfhibbbdjiggdafgggcifagehgfcefbbiihdjagiagjicjdjddecggjfjefdigdgjgcdaheabijdgijejaeciehfigffighbcigabacchbagcfffcdejhaichbbaeahjghdjbjdhcbebabbhbbcbafdcdcdifihiijjjfahgbhfcjhbiafehbgaafbciebbahfaihcfffabcfjjagbajdgggihhaigdceaaacefihicjbjdchehdjhbeceiiejhehcfhejbegceebhjiejhccagdgbibgjaegiaaaffdbiejegidaegibhdabjdhdcahaehgaihjbbacbcahijgjgchfegfdbdccfhcghdbdgiaeijagbjfgidaeefcdbjdgeaddcdhdbfibagjhgjjcbbdhehgjdebgejaegfggcfejfafieciaigcedbbgedgjajjcejiecffdijggffehjeacedbahbfgdjgcajgdjfcebghbeihcfihaahhfeibagjcjhdjgfcjgjdbbadgefffcdgbggbcgchdhddjdaabddjcfghdgejcggbijfbhihefechiehiahijbbhjdbfdcdaihaaaiccgefbhdiefeafdebihbhciedeeagbgbaibcgbjfidbfhhifccadcachihcdcbgihihjffdafcjjdbjgibbbgebdjgccefffcbbjhgedbgcachbffeaaijcfiahdeaecfaheaefegdccaccgicadfedhhdajehfjieccchhhejdaafgigeiafegdjajggifhdcdachgghajiijghjaagcihdhicaeibijjjgfhcfahegcbjadegbijdddgebcfdfcjacdbgedciefgdeggdhhcejdbcjdfgjihggchdceahchhfhcggiihfghabiadiaiiaiejdhbbjcceidffegcbdedgegaeeefhhjhcbadeichcacfbajdbfcaghffbdibfgeaeeacicdjfeiijiedaffjbchchdfehjfcghfeadgbddgiagjddfbajedfeihccbdjcgjdjjjcddeffffbdhabfcjcifdfcfefjfcfcjbhceaidihfffhfeedegjhjcfgfijchceidajgidddajhfcdhjdcfjihbbjgdeefjahhdadehfbegcedcjdhgfagcfjeidbcadagfifabgebffabbfaeidhedigdgfgibfedgebaddajbggefhbabbjihggeefhcbfdfggjihagdcjcijchaahfbeegjjhbjjbdchibhgghccejajeacgegbgaeddhecjejieehbcfhdedaifigdceadjjihgbegijgicdcebdfjhidecifjeabfhahebbcfhaejdhdcbefdchebfbcacbeegfbhdeegeddbacicfgfbegdajacfibfecgidicjhiehigcfiijicdgafbjjfcccafcfbhejbghhbbfcccdgbffcgjbhjgeadbegcbjacgjfaiagafeddjfachecejhffggbbbdbddefeighhddbdcigdiiiggihjgffijeijeeggjjdchgbegcgcbacjgjbfjdecbafihghfaicgbaihibdiecjbfadaechcijhbeiggfdigheighfjccifdahgecaijbediijdbjeieaajajbcdacijhcgedhdihhegaiffjfbaiicjedhgiadbddhhahjjibedhfeafeahabhbfaechjabhiiiigiddedgdhadedfffhcfdafhcjddbhbahhjaiffahgbeidgbfhigjidcjjdgcafbagijeaababiecaggdhhcaabfadgigegihghgeddcciccdjhdcajdahbigedeihafbgbagdgdcjhjabjddadafhjaeaifhjegjgcgdefjicjehafagjfdcdhibffjdgigfeebjdcabdgdicjhjdbbebhaahbafiiiebeejjahdcdbddfifhajfegefjgcgfefdeefcefhbjifafcejjhiaijbabafijbaidcbgddhabjijfhbggadcdahageccfadhjjgahgiggfhbheeabbfjjdjcbifhhbedafadbefiedbjghibedjcgfcgicbhbahdcdcdeibhjdfecajjaihejedhjjiijabchdjdihcibbeciidcgeijjcdiaaadhbcbfhagggbjajfjihjajbaagifdhhghhdacigccebbaahcafjfjcigehiehhchbffhdaebagcdcjbgehfchbfchaaijhghidjbbcajcaeigahacjjhefcehfbaddficjhbbceejgfdebjfadgbbijediigecjfdaafdhcfecdbdfdccaejjeifajbgaceccejaacbgdehhebhiccbibjcfbigfafbecfjbfddhjefjhjfeidcdbdgbggfejbaijdadicgciieahdfeabhbdcjagjefdehjeegjagjcfbgidiehcidagijgeaecjadiiijeegcbhdbhfhjhaaahjhcbagcadgjahbdjeifgeegagahbgbcbeihbjhcbiadejgdfdhjdbgbgdeijfiehgbighbcgbjjeffbcchddfdabedagabcigjjdjbdicaghhifbfgbjchacbfidaiehdffhbifegjgbdbfgigdgjeehjifcdddbbgihiicfggjijiajehjbhhfjfcaagijaihbhbibgegjjcfdfgbdfeabcajjhjhcddiciegaibcffeaajbcfjdhgdfcgdggbcjgfdciffaaeicfjdfhbbeachahjbfhhfdgdfeibcjhechgefceacidbcjbibhfgjjagfhgbbjfdcgccggajhiaigfbhhieghcdedfijaaabahdbidgjfabdgdfebidjhajigeihgdedfgihafegdfceebhaacbjbicbebgjgjjeibcjdgaceffbjihicdbiijcdfjhjgghgaigdiihcbhdjafdacdaighaaccdcghefidhiabajbeieiaiaajigghaacfgbfeahbadbgjjedcgacjchdhgbifbhabiedegfcfdhdchfdcdbfhahcgdiggiehihddeajbafgjcaeedhfiegcebfdgbhghhffecgjjacedeedbjhfcijheihbiegfcbcghfcecagjcfdijhgifjhejchejijhbebcjeiccjgjhfdijagbiachgibaicecehgabfgicjhijjccficagfddfdjebchbcbgigbgajefgjcabefadgdggbdeabfabicdaefhgjfjaiciaacgfdfchhaigeceedccfihjdgjffbcejicaiceeacbeicfdeaibcceejbiabjghcieegigcdjjabgabfhhdhabididecidaffhiicbdfbidgjgeefaaadabdijijdabjibiegbccdjdhbgajijbjehhjaadcjdijaijjdaidjjacbdhehcgeffiafjhjjfebedfjjiicichbjgjigjgcidcgcdajahehgfjiiegjafhbbbgjcijgcfbhecfiajiehcihbbdhhhgacefeihbefgicedeiafjihdggdgdaeijaaaiiicggabjcefeeaeddahdhghaecgagjgfgdfabaffahcbadfghjagjfjeghgdjfgeahiefagdhaaebfhabbbafeabebjcbhbdehhdgfcgaeaddddhagffgafdcfibahciefabfgcjicfaicdheeaiabjcfjaehadjcibbeghiifgihbfefagbdcgahgbhecbdghbhhjegdacjcbijhaighafddifabeagifbddihbjidcaabcjfjbeaaijjfbjfhfhbhjjhhggifdjfcgbbcefdgbbeadcifcegibfejdiibhdciejigjgfgeeigciegibabdhifdabcgdigcehfdbfgfgfacehjdiicehahgggiifjcidjjgcehcadfbaajgaiiajaehiceffjbhicfhcfeeajbbahchhafegabadihhfeccheihjfhigbhjhbdjjdiffffagdjfihdfjgecfbbebiceechidgajchgbbcjbjcffiicggccbjhgafdghbabajhggebhecbjecbbbidhhcbeagddefaifdgbdcdiibdhcdgjdgjjegjeabbgjaegjchhibfhecijhaijjhgciafhgbceaadjgibibhegighgfiiecgfhdfiegiigbgaadcfiehbcgehdchbeibbjfjedaeaieiafigajihhejgdbgdcfeideecebiefafgcfjcghihjgdeieccjiegegbfeaheijdjdbgfcjaecebaiaibbecbbheibhhdajabihdcicdehgddehcddccbffhdifhfegciccedgfbiaaahjhgbafedbgghcjcadaffagfghiagieacagiihhhjigjicdedgcfbggcjcbicechddeibjghgehicgddccggbhdecfhbjdedbchebbbjcijjcbbbebjedcabcijchaeichdahgfijjchbajabgagdcfeciejghgfgefiiigggiijfabjjaecbgiaihcjdegdiagdeebbbidfccgehefjbddagedfeeggebfdbidbibieabdaffbggiajbejdddbbgagcdicgeeechgdbdegjebdbhcabjgigcjcefdjjdhghcaaaiicabfjbcbebiccbbehhiadahbibecgfghfbjhfcdgjbfgjieahhehgedcefdeahbajgheegighdjjbbfiaffhehihhjbhfgihaieiaijhcdhijbigdhfggicjccgeifecifdfacjadahhaadaicfjbfhhfajijahiiejjeidfhefjijfdhjaigigadchiagdefhjefdbcjjdeafajdgaeecfgheibfbigadajijhcfdiffcefbjfajjgcdaiicdaajehadhhabcjeegicfiddjcdbcadhdefjcjhgbbdgccfibjijejeedcjcjcabighjeaicegaejfieebdfdbfdgfadgbhihfhjegibbibjbgfgefafejjfacigedcbididhdcebhehgdibcaaibfifaechcicecjfdhiaggddbibhdfijgdaicbgfigfeaebeechagfgbcbbdbbajgjiegbjfiaaacbjijgibcbjibfhiddaajabgffdebhdgidfbcjddhghidajeibciifhgjefdaiabbhbjfbadfgiijaabbhcjgicdaafghiijfbdjjbabeghggbjcjhabadjdhjbbeffeebjfccijbiggadeihifffdgieaidbabcjhfdhhcedadjejihbajcedebgcjeigbiaccbhgjagacagcjhafbegfabdcdicbbfbaiefahgefhjedhciccdbcgijfbeeedfihjbcceeedecfichggaachecdjjejfjaccfiiicecdidgfghgdjbeaijaabbdbhifeidcafjbijgdjbffefeciaacbebbiheihigchfbajgaajdgeiaghidfdjgigjbcfgbahgbeaceiaiafhffbcgggggjddhaabjejddhicbdifgjjfidjabjibhdidgifjbibhdcibgbcihijiccfjehhbhcbgfjichhdadbdgbbhahdefhhhibgabeiffjfdbbaeafcfegcjacccibggiigdeddagbaejehigchabcggfedhadjicibcfgaiahggbbcdcdiiiecjgjagegajjcbebcjafhffbjdajihiffcaibbjjdjgghbhjcehegbbecbjhgjbihefjifigccbedfibifdebhejeiafgehdaibchegfdiejichejgacgbhjabhacggididbhajbejaecdijadbjiahdjdbbbeaijgfcdhgeeighjgehfeajgfjcfedbjeiffibcjhfihgafjdbbjhjdagibhdhjaiebiedagcicjfacgijijeeebhfcgbfiigieijfaagihbhcjehhbdeijadegehbcahfhbfccbddgfdehdfhigdfgdfdbaaecgjchcdjjddfeichigbfcehjjhfadjadbgajjgicdfjjbfcgbehedgijifccdfaaibbcehddfbffhggfaiaegbiefbgjgcejggejiifjjhiffiiaaciidfiibbhicjgeadfchecijajijeebffdebfdjeebibfcbjfefiffcbbdfahgjghjijbdaddcagdafbbdcffbcfedadfafeaihdgjdeficbaebbhjjjfieefbfhgihaehhifjghficjeifecjajihcafccdfejfeihigfidfieefefffjjabgheijfhfhbheafaadhdjdgeajeegcdhfjecceechbedecjecbjdegcaedcjfajicbdddefahhchjeifijbbjbibhbdgbjbeaechghadfifbciaigffeeeijeggfdjhjehbiihhidcgedidaeciaibeeaebbiicehcgddjgafjidjiaejgaeegjjbbbibagddeiebfgdhifbhjhehgbhggeicaidceddjhgggeefccjjbegdcficgfcccgafdeehedcbjcgdbffjdfiadbdebefibfgjdhfjcagcacaejahjcdcgbiidbdjjaieijagaicfhjafcghjbfeabadaaehdejfgjbdcejidajgfidefcjicfajfbighfdgjbeehghfchfiaiejciffcciijhiijdbdfaffgefjbghiecgefjfhccadhgggiefegdccdjajechjgeifihfbbgecaffefhidjaaaeecbbgiabaecjjgbggidchcfacebheddccbjfaafbbjgchhefjfedhcigciecbajfcgdbhjfafbbheebgbgfiajjieffejaafgajadbcijbihcgciejijihjdhihjchgdjabfijeeieibaahbjeaaccjhcfchhajcdcidgghjaefjbaabffdhggcfhgiiiifddjgfdajhhejfcdhjcbgjgjjbdibihjahjeggcgbeddjicifigaggdacddabcadahaddjdjdgahahgdddiadigeegebjbggggfjfcjbafbhcddfjgcibebefcfdfigjihecajjfhagagcfbgjdbahceffdjdjjehdejhgjfieeaecjjeegdifibgahiiaghiibghidiffddgjhbdheaicbbehcaicdbfiiggcfjcbfcahbifgahjhgddgbhbegcidhadcjiffjecaedijhcdcdijeaghbebccdaaaeechaaaifjdaedhjgeadagfejjigdjdafddfgaeaeiibbghdccieggbgicidiegjaejgfjgjhaihhgfcggefhehaajfjbgfeieigiaffhdghbchccdaicecdcjfihheihhagjhbcihiigejeacaecaacbjcfjfjcfahgfbgddaacdieghfcfeaffbjgaffediihadeiidcaebeifhheagcdajhfhaacecigdghhbfhcibigfhhfhheiddijhbejeaiibhdddifdidfjiadccfiffcddcfeaigaagjgicjjjbicfbjadadgjccfjddjiafbchdchidaddifgafcjfjhggagefafgggebfdiciajfgegehbcibiafehafdhbbcjdadcafefcaagajbgjehbigfbfajacdjgbdjgaabbdiibeagchhdcddbcdbfecbcfdcfhejfdhjjiibcefhjejeafghbccejehehehcaifajdfhabegcbbbfgcfejdeeaggbejfdbejgbacbieiejgcgabhfihajifiebbacjdhgichbediefjefcbahaeefgabijefjbciafjgiabcefbjadheggdgfdjhfbbhddhfcijfjbgiahccgiejffjdehbajjeejgfcgihfejgebbigcgddgifhdifedghahahjdgeijhfgbeibgacabfjhhighdjafdhdcacjjifdciebjefhijhdjbhjjdjhdhecbbeagefeihgbceffheddaggcigfeadacdabfidegjhieahbjjiadcbbbghefeebecedeffjdeidhgighdfbfjibfiebigfcbdfbjjbahbcgiajbihehbhddjgjgdagbbedeadebdbdgffgfheedficbfibihejbfiaddiahaihiijdfbjdbhhabecgfbgceebfhcgfgdcdbgfgcgibajdehfiihigcffjbdbcefijaigdgcgfhijcadcehiiigdebagjgfchiadafeigbbjbbgiegiihaibddgffhihbhjjjicafebeiiifihagcceghibeedehbdajciaiahaghjfeidjdegcidgeeicfhhabafijffcgfaicegafgfdfcjgdjbejfadghfhbifgbbihabdhgbcbhiiiadccddhcehchadcdgfieghiibheagcdcieiifeihhjjefcfdfbggjggbhfdehhgeaecceccchjbeegjcgahjiaeagechdigiecihacgbfggbcbcfafbgaiicgfcdgggdcfgddhibcahhjgdagdjiacabjbhcagcdbaiicadghdfcfhegahghchjicdejaifdfheiheicfcahjacgaeabciibjdiiiafjahabaabafeaghjggfbcdgdbbaajjadjachcfijcaihifdiefdedehijdebfdahcggieghjicjfjaecfieibagahjhfdadfgfdfgbfjgcjhcjaiccgjdgfehhgbaeeigefjdafghfibeadchaadbcgaiehafdcaedejifghdfiefjebjaghcejehaabhgiddbchceghjedgfgcfjjcgjgjhicififbeccccbjdbedabjgbcjdacgifjbihbcfifijhjfidccegegfbjdccdeggddhgdcgeffachhbgeeddacagdgihgiebchhfabjihfjadaiiiigddecgabdafgafhcechffibcggabjbghjibdjgbbbibcbdbbgefdbahajdbahbghehbbffchahcabiaegdbcabbhfgedcehbjibhhdhdghgchddjebeaifjgcaecccacjhcifgdhibfcggajbfbcieachbjhdaiegdjiifgaidbebdfdegiaidgcefhaddaaafbieiafhjjajgfjjggjjhgcihhhbjchbjhigfbaiggigefeefeefigijfiaieegdhbjchacagabhagjhjbdbfghhdfdadefegicidfeeeechehiceabfbdchcjhicdeiiadiefaeeiieceiafajedaabeejabaidjedijehhechhajiefebiddagdcgcdiaediafdfigfdeiffacgjhgeecgabagaicfjfdbdbbdhcjhgijjagdegieiiabiigdfigdfgfidajhbcjdhdjdfdfjcdfeegaafiihchiechfbeaddcgffdegaafcagajddhcbcgaaihgbbjjeahjdafchjehidbhdjbcfhjcfdeaieiiabggjagadiafifjhbifhgigajeaagegaafjjfjajgjiechcidbbchgcdjfhjcjeegdccfedijhddigbhaejahdbhebjcfdaefhaehdjifedicgedhaggicfjahfijegcegihbhjbajccgffbgbbbjbjcgjchjechbbdacgjehifegebefjcibcajejedcghebebfjheifcadiegcbajigfifhdddafgebdidfcagdedecjicdeaaaedcahfbhfhchjbhgjbjfcbibccbidgeghgjhbbaijgaediaefcahdcgihhibeehdejhgdcdfjbgddfjacbeidbgggjgghbgghcfgigdgdfheadedhcejjabbfiadjggdghcdehjbhdfggeefiefgjbebgifdbdgiaddjbddfbibbfdffechgebebbdddbcfhdhhgjfcadbcgdgcahejihcgafdffbbacbhfdehehajfigdfajiegdghbagdedibjejghijgfcdfbejbcacjfbcaafchjbadaedecheibcgigfabdecdefcafjbegacadaegcjbjjdjddeefbajdfiaegcfffadjcjhjhfaidjagjjicdccebedafehfhidcehcadbfhbcjjjjicahhcaahdcbebegicahhaifihjbabhjaaebgcbchgcfejgffabbgiifhahbadahjafbjfhfbecfbbjjhidjdbhbijgecebdedgjfgggbadgadifbhefdjdhfajbgjehheihfebhcefibehhhbffbdgdcedggagdcigfjcgdehheaifedehffbgifiebcjcebahchhgcijcgchdgfjdcjjfeajacjdagiididjgjajighhegfcgiaeceacchiedhbbcigfhecfdcbbegbbaagfgeedjeejgfabhhcbjeheiifbbbjibddiehedcfgffaebdfhgaajbajfibgggibifgfaagcdjieadciicgfebbjaigcfhgcbhchhbdagigdjabiiehcdjidceeciefihcdjfchbacejbjdbhdjbejaehbiebjhdgfeiiafaiaiafaagbfhhbceiichhjhdggeeifggeaibfbejgdhcgjigbdicfejdhghbcegeegeacdfijjbdccbcjecheacfbgfdaficfgfgdggccbigcbgdeidjaafdeefaadbdbjebcifijdcjjggijbbgdabibdhgachbhiedbfbeecefcjcgcbdddaffcbfbgfdgehajidhdhgjbefjjcdifcjdgggibiicbgeecdjeiefcajchcbediehggffiachhhifehjcdjghagfdcgcabfcffaaecefdjfehdicacgjadeheijhdjgeffghgjihgjcejjidjidejgfdfihehachdbjdcijeaicfadaejjdibbjebehcegaeegbehceacbbhdgichdgdfiffiigdgiebihfibjdffeidfbcegdebhehjgiiejafegcejhcgheecjjhdicededejhadcdhjegegijgfeahgjgggeffjiegacjibjhefjeafiagjcbgjgcffefhbbaaeieeddggijehfjghigahcehiajcicehhhfabbjcgachbhhaedbicebjdbfdfadbeihbgecajefdcgaedjigcagcebiadafjadbfhbabfidcfcdcgabafcghgfcfagdhhjccibafgcgagfbeiddcbjdhiidechchecbehfbhjifbfibggafciaaecdbdgaibagibacdjehjdjheifcjgheejaagjiajbihfddfhidjceebeajfehdabegdeiieaeighiigfchaifbghieiddgfjbjjihbggcjbjbiieccgjeccefciejgcjcgafchfgghbjeeeffgebhhgghdeijdaajebcedjgdcecfdhgfigeiddhcgbjcjifaedjbbgihfbdghiefifadahgabgecfecadjafffcgabadagddjjfabecjecccehcbagcaijcajhcihaachbfjefbfdddigieieiedaegjfcejbjaciicjhciifagjhigigahajgdfehcjbaffdbidhcchcafdeihjgcdggeiciffibjabcdjfcgdfaefjhdbbcigeddgfaefibbacfdgecjagaddfeedjifceijfcefjdhddgbgacdaffjedhafjidafagdejheadhgefggebgddgjgihbbecgcdgejbifbcccdgcgeijidfdahdhaijadiciijdjaciahehbghabbehabiaijaaeeaedihhijjedbeiifcdffbgcgccjigiajgfaafhfibhfbhbbbcecfcgbfgceifecdjabaaadfbcfdifiagdejecaigicjbfajfchieacdicjhjddafjedajhiecdaihiafeecaehdidbdbfcbbhgafibeejhfbceheieabjhjafdgjihhhdeacbgeieggcbcfdehebhebdefjgeeefabhfcighiiagddbbfbaghcfgehijcaechaideggjahdagheieebciabadbhaffdaejcjghhjiahhddddibcfijgicabahffeedhabdagihgghaacfcjcedhjiaedbgffecjffdbfbhjeghdcbeibhjihedghegihciidbfedcfdajdgbcccfbbffedjbciadibcjibdhdbaafggcagdiibiiigcgcjjbdfaaejgijdghchgabcdcfhijbeiaffacigjbdhccjjdjfdihjfaijbehejhfbjjagadgcfceffgabaeeiebjfdidgjfajhegjhieabaaacajidebafffbdaabccidfbjdfieifcdaabbagddgdieagecgfbhjfjbijibigfjaffgafaebgafjghiaigehhfbfhdiaafifagcjfefcehccefghjbigdjdghdeeiaidbbaeicdbfigafibcchccfhgbdagihhgjaiibdffcbeabfjjbbdbdcbijfecehcgejddgiaeaifhgebbeajdaigacbabiegigdbjhgigeihcedicifbgecfjfdidajfcfgbegfgejbeiddcgjhgfbfgijeahehjjfidcjbecfedejiiadcicchbgcebdjghcbabfeggjcfigffigggbggeiibdejefhajehejaajcghhciadjjfihjabbhbjacbifcegiahjfbdjjhgbdhbfehhhdcicbbgaicjehdiibgiibedfgecegibdhcicbgeijafegdfgedbfeffcdaicfjdgbhfjdjfbgffbfbciicgbcigjjbdghgedijfdiiibjcjejdhcjchgchejedbabfibhhejjcjfjdfafdfbcfdidhhgjdbhgehbedfdehdejjeeebijibcecgabgjjcbjfaaihdiiibcghcidabaedgjdiiifhehgejcbcjeechdaihbbeicaefajajahjggdgcecaiadagghfjgibdehfadaejifjhidjijffijjcjbbjiagbdhbdcceibhjgiegdhifgejidebiihjaccggcidcjcejhefgghfgbgccfabhibijdfiaihbffjbcdfhhcjdfgdficbicehajiaciccfjiieiggbheijeicaabgciagfcbgaeffcbddajgdgcjahcgehccgjgacahififcdabcbhhdiiidafbccchbjfaddchgefahhcfechiiaciaeedafiddbegbebaaiaggeihbbageejjjfdgdeeaddeijdebijhebbddjjjbdabfgfbgjhagihjibhdegieacdgdbggbhbefjdfcgfjaccdfdfddcfcfcfjdbiigabhbcedcijaabhijiebgjdbehcbjeaajbhbfggbjccjgdbhggjfhdafhhfgaigbgfjjhgfggdddjebhghiciededgajebddjacibeehhhbabbafbcadhfjjahgjdgicicdiagfeaiffgdjffcjcadhbcieaffehjbhbiafgjiddadjjadadgicichjdceghejhcchbggiicjgeeebdidagagfghcchffdhafgeiccidgefdbehhggehhbiajfijfeafjhjcjcbbijjegcdegiigffgbgfcaiceacajjajcchjhibihjagbbdbahhjjfajfeehbedjceidaajdacbcdgjgjeajgebegddfacddhehcfdfheddddchccafadbjbcacieeiibdgebjjiidjeaibdiaiiihgifebgaabhbejbigfgehefeihiejdjehcaffhchicejaccffgihiiiagebdaegcgfhfjehidgbadjjchffaiafcjjgcefhaeafdhddeafaedccdhabeicjjbeaghciijddiiiegaibfdedjdaaaeccfcadgdcedbdiijdchbbcbedfdidaafiijidfgbfebfdadbbbchihachhhcdgjafaicjjhibfbibhcieddafgbcafjgaehbjbjdaaigeeehfhaahejegddjcjchicbjhhhbaeaaiafhgbbgagcfhhbdhfahffjieiididadjihgdjdjifiiedbbdcgbafcdgfdecffdbbfgejjddhiccagcfhchhdjhdiggjbceheejaejjfdjidediidgibcjidfiicbbbfhcdjccijcfifjjecfcddbjhiabijjjghcabjibeiadbcgbiageafgfhdicdgcfbffdcaibeajffibjhibbahdcejieedeichjccaibjcagffgaiehceaahgggbhcgfijdccfjijehacdiefcjdghjbehieffdbdhhijhdhcdagiiaahhbhdegjggadagcbebddjhbcfjdhcdiegfbigifaebbbdcdaefdgbfjibbdiiiidfbeahhjhegbebjbagiiejgfibibefeecdcagehjhddcbaffeciidahadeefjgaeeiabhegjfbajbbchcggjihacgiibijifcfcibachddcfhjadgihagabhehabchiachdjbfbgaebcagfefaeeaidagehcchjbbeajbihidfcaijbigeijdedfeahddjccchcafhcfhgaiabfghgdbjgbgdbigiahacjhicgbafbhgecfahaecfaecjicbiadfcacecaghcabedjaigcdabdiffafgigcfjfhejgiijbecbcdbfbjjcijebdjedbajabicjieiiaiddegdeiijccjdgcahhhjfiabdbbgjaaaeacdcgidcieiafhbdfhhdcagdhiegecebccbeehfchaaaafefieiccebgajbfhhiecjfghdihgehdidfehidcfhahabfachahigjfibbbihgebjeidhicaabigfjgicehfjabfiiejifdaihbhjagihfgfjdbibaejiaadiajidbihfadgggaaicjehghdjegjafccgbdhbjghghgjcgjhbddaacdihiiaibehdafjbfhjgaibfcbeihdjhbdfaefdjchijcbedfbaajjadebbhgdefhhhcfjjgiacjgbbggffidbjaajbeicjijahdhegdjagidafjddadaadafjcbcihjbjcghhfghceafagcejadcafdecheadajccbeccaifdfghjjiciefheibjccejafehjffdfaghcjbccagdhfadjafjbjijfhbgfjabajadehfifcgfejgibgggeifbabgaefcaeehfhjiebhaadaeggajefajdciiiiahdciihfcfigcdeaaiibhajihadecgfdedhaffjjbfgieefdjjachbiidjbfiiaejbaiehdbddhgeedjiegfbdhhehjjfadfiibchdcdfghcdfjfbjeaefjejfacedfaebchffgijibjbhdbbjecbbcdihgaabaffhdfihhagfjhdicfidgididifcijegeadaiadihccciigijccbeagheigjhbhcjghigdhjeigaafffceebagjgdhaijiaghcfibbfdecahjaijbjbjbchcfdfiaicfgdebceghhhbchhhgfijgbjdebdgfebbhijhjacejjbagaiecfiicbgdadebddfgibefdhcibggdhhebffedfadbhceddiaeggjhafieijhhaeedjcaccachicdffjcgbdaaeaifjgcgjcigciaaidjdbjfafacdhdfdiicjcghhddebfdgcdgjacbcjjhjecdfcfidhcgfcdcdehjibjecgcejdigfeacicjhiieifefbdficiijfiaacbdffgfjdbhbjfagadgeagjbaigdaaifdcjiefijcicchaidhhjdgbfffiibhjabdigchebcafjedjigbfaihebecgafajaeecdccdgcgdchdbjdjfdbejfdjbbedaiehadiheiiiehcfcdghbbgddagdgcdcifaiifdhggbfjjajebggjehffgajeggffiifdabaeigjieefaiiejggiaegfdchibeccbfjeaehcdbiedfdhjgbaffgjadgggjhjiiadgfgidhbcjbccbfahdgfajeahagjddeefgjegggeaaifbiihbfiejgbdhbcbhjjchdbeiagjbdbefjigheededbjgbggbbjjcidjjbcdfcagggffejdeehijifhicifhcafdgidgcdagdhjecgjibdbefihacfccaagebghjeajgghdiejhchccidafjdjcbibficjigbaahjcbeccabibihhbdehjbficcdjdfaciiagagjcajaifgeccgjcaehcgjjcacejchfdhjfiahfhgejejegcijciihghfageiedbibicgfidghiiicghjdiagigibgbbgfdbcfhbgaehfhjcfhiihajfehbegfiihhfdjhjhcdabaddejaifheifhjehggejhcfcfeidhbcabdhejcbjcbajhdeffdfeifaiihfebahjecdidjgbebjciagaihffjhebjjbeihiecbdhhgdaffeefecehgdebbhbfefbjhdfiabhdadhfiehacidciaccehegcffhbfbgdidagjehhddjcbbeeajcadhcbdiigdfehggfibgdgiejdiiajagichcdhgjcbhjdcdeicgahcahbbfbigjgeecijhjdfjeadjgddghiagfidjjeeibiihjibihejahcgjfbgcefffcgfgddabbbcbecieadibcfajjgabjbiefdhgdiajijfhebgihecdfhicbbhbhcbjbiggcjgdajicecbeejjbhiddbifdfahjffeefgibeedgciicfabebefjcejbefgajddhehecdeefbajgejifghiddbjhfegdiachafefbidecggacbjjeecfhiibghjegbbdagafggjbhfcbdcbcddceifjjddcieadcafbjfiihddbbfjifhjcgaefgbbacdgcbdigdheaheaejdfiiahedagidbhdjbdgjjcjibfcchchcgeaegfbchdcdbhjebbahjdcijjfdfhceeiidfbiicadgebghicgeacegbffdgfibebecdibhbhefjdjjcghcghbcdeejbedhbhdaabchcdgfcagdebhaifbjjgjdihjahjfhfcihjeafdafifhifiejcbhgieefffgiehifdaegebafjfhfcfhjdbhhcgeaeagbhjdhahhbgdcdjdfcgeedhfiidgcjciigdbhadehdgejhjaddchbecjfgcdeabfiieieddhbecddhaebfbjaibhhigichbcgbdcejfidfdcjddbfchhbiejgajfhabgefbddiaijidhfcgchihhaaifjihdibgaejffjejecffjahiahcgibgaccahhdfgccfahfjcdcigfchcgjhjjbdjfjdhbhcfafcejbgghaijaejjcgbgcghihafgcgggebgajdicidcdigbcgeadfagggjebgadfdgfiadabhdaediheaceahjjfaghdejchjeegfdbgjhihfcbaebffhjbgacfdjfbjcefdgjcijjgaiihcgifbcedddbgajccebhaicbecbedbaegbcgcgjagihiajbecfecbcecacdeihcahhgjcfgedihigbhjchcidgcbhjhfbhhdhbigffhihgadeaeeejidbeeaddfdebcbgbjibdhfbjebghjjgdiahebaajfifjfcidijfefiieceafbijibjhgabdbfghejgifggcjdjcfbehbejhcgeefidedhdicghjehdifeehdbgaecaadcjgfegffjicehheebihaddjjbgbdifaajcdgacdcehagjabfjdeheihgbeidbeigbjgigigefgegigahebfgigcjggjegejjbcbejgejfdfhhcbffaaehdghfejjjhbjeaagchcicgiggeggghjdeghdeaibbeedhjcjhihfahghibdfdidjghjiaagdhbgbcieddbddggjaecghechejfahgigajdegdafjjgedjjbieheeafbhaedccabjhfjfgfjijhabeaadfacgedjegjhighhfchjbbjejiadbfajeeeiabddfbeacijifbigjajcjhcaagjjabggcgaiejiihadjigaiaigjdeiaefhhibejfhcgcajaceaecahehegecgehaaihjihbeaedabaeecbhegeiihefiihbdjaifdfcidejhibecibghjhaibgeeabbiedcdfijeaecefghccagifejadcjggajibjffcegjgejhfbdhfhecgdjfdabgbcjgabgibffeaajchcjgideaigjgcchdcdidibbehjjhacdifajiccgdfgfedcdccceiejiaadijccfhhahjdhgfhjhcgehhdbgfdjbdcjddecbegiabgebdhgadcfbadbibjdjifieidjgedhcebjjaajeadbgacjcdchjefdbfbfagdbagdgijfdejedebaffgfbddciddcbhbheiifahdacgfgchifbhbbbhgijgdhggfdggghhddjeadjaiiffehhijbhehjfifbjfhbcgiijhdagbbegfjfdeighfeiifcjcfdgaiijbejfaahbieicdchacjdgdeeijhggcdgfejeffgbgcdhdfjcaajdjdeaghdigdhaeefbjifggbajadjfgbjagcbiegacbbcajjjhbcaijgcccdeiaciegcgcbahdahiibjdjehbhcbfbahjibgacfehgjjadjccdjijaddcdgdjcbbhjbidehfgdidbidgjicadddhjigeedafcbfcbajefbheaagbhdjfjhbeiibiehbejfbcdjfiaeaadgegdcffifcffjgjeibbcfjjbjgdjjabfjgbffaefaficgeiihcjbcaacbefjagfadjgjfdjeghgagifdibcahddejffggfjaijhjifbgdjabhdecdiihjibcjbehbggbiibhadbfjhiadbgjfaeiejhggigjfejfgfadcchhdghedjgcaajbijhagbicdeagcifibdfgbdjffcadahejjicfgjfgfbfiechghhaejbjbhffecahigffeiffdgjdffhbccddbjheeehggijeagjcfajjhibhjefjfjabihgeeiihegjhdcjadjccffgaejchbeeghahbihjaahggjacaafbadchifiifcfeidbiggaggfdadafdigedbidbfcaaheeffdhiachiaddidchbibifaccjbjfhdhiabfgeagfdjgjbdcegdjihdgcaacjdeccecjcjfgiggafeadjdcgfieedaihcjdhgcageehecijfigadideahejbfcgdfdfiebbfgiegcaacgdiffbdjeghdhcfhijcdehdgaghegjehghjhaebbhcifgiehhdggdjbcjbdefhgdiejbidebgfjdgjfcijajbeajhhdhfbehgfgdahhhbedcfahgbifcebfhfhbhcdfddgdjaeajdjegbjchfiahjhagjjhadgajfbhacbbjgedbaibbbfiehjhadhfgiahbciaccabjaghdiijaebdagebbighjbbbbdahcjbcegbcihfaeehjhgdfdgbbfgbbcihhdcfbhfcdeeidgfcfaididdchccdhdjijhbjfafgjdgdgigfieiecbcchhiheedhjciieggeagcgahffcdajbgdbhegdjidbdidjhdadfhebcaccabejbjggijaccfjdibfcdhdahejachcifbbdicgdjafadddgjigdjggiijhafghcbhaiebibfjhgdchhjeiebcggccaaicggiedfdcafcgaffadbgbcibdhgedhdjejhjcebbbaecfbeegjdbaagahdddeahdccefafaibeheagiaifdhbfbhhaebfjbdjcahgfhhicghjbjfbaiaciigjbejhigjfdgegchjgaihhbibihfifedcchcaaefbibeicgdjjijhgecifhdedfeifihjechccdjdbaibddeieiggaahdgdgcjgichgibhcbcjhddegdahaehjgcdbgbdhdbbbejhjchadfjgcefahhchecdbihgedafaiegjcdfjiedhfjjbijcgihbeahcjebcdchddghgiabgbhidjacgbigbedfgbhghaihhjaijchceibhabchdbiddcddffaaiediciejebjjgbjciiaehdhcijiigbegdihdgjjdgeiafdiececjfdjhfjagcjdiedjjbcacbeiaggbfibfgfficbjgddghacdjiagdegfdgehbjdgcafgahfieegjgfbedidcejhaieccbgegaecfeifaehghchdffcfeagdgbcdjfhiieabbgjecfiefgecbcicbcedbeeffidihciijbcgibhddiajfachcefejdbjeceafeibdhbaffjijjihbaafbhjjfejgagehefdjfbaeaibcgcfffbhfcfgggjidbafbdhfcahbbhifbfdjcjjcaigjgdgdhgfebhfgjhfhcjchaigegdfdjgiifiaddebibcchbijficefhijafhaggdhfcabcafbcijbcjebhibbaigcighfjcdabdggejbdjbhfgghgjadfbgaiebbbbbddcdacaheaggeiidecejijiccfgbjabhidfdfhcebcgcebjfegcfdcbjdbbdffjfggbdhbibecgdeafijgdcbdccihacfebcijfijgabhgdeecefejhdehifafhbhjbheahgdejbdabjafebifjbbadcecgjeaejhdhciaecjgibcafdiegdbdhbgjafhbegefdahajbbcjbbifaajeggcdfigjdaijjfjffgcghbheaedihaedcdbdhbgbedfcjcfdiigfegjjhfidhhghbiiggefebaedfagjcccjhcfdgibbfajhdgbadecdfaabgbcagfcebjdcifgeehijdggdgjbffhhehbbhdbaihjeffaigefhdcahcbjegcfeifgfgagcicjccbhdgibegjdejjabcdjcahdidhjghbihddcjadbhjjjbfcighggjigbcdfjjhjehdcdeiaagaiffajjbegchjgadijedgffbifeifghejcgcghigfbaffigdiihffghbcfbedicdhcgigheeadcaafbhihjgccjaiaaggfaigcehggghghhifgafabegjgddicbhjhhdcbdhdhadbeeaaejaadhdghfgacbhgdgdbifabjbigifcfeejhbdeggejhidfaegacajgiebcihfafheejaijecjiahihbbfcgieahhbbgedeihjdhfbhaeghbgijjjaeffceijgdahacgdidbjdgifaheahadfbidacgjbegadigihegjfifghbbjgcihafdcfeacgibigfbjfjdceeedjehaaggjehbdfbiabigaiajfiigcjchfaaejjjeccgjcdgaihdgcbefedgchhdgahhgcaadjaehbcdaeaciajfacfafabeihbahjcejcjjjebhiihfeihiahjcddfbjffihifhibjfhfbcdaebgieejfbiiiiaieghajbceefgfjjfjfgfbffhhgcdjedjgajccdggdjcegbidhgjhieieijjiggbafgfiahihabceaejegddcfeecjjiiigbbfaifafeeffcjcgefigaejfcdejffiiaggcbgfdhgjdeiadebfdfgcbhffhdjefjfagdfeghdadjhbjicefefgfibjajcdbacjjdfjgdjjhfehjfbighjddjeccdgiiahheejgjjhcajigeabhggfdhhfejjbaedaddhjcdjedhgebidicgecgccdjggfaahbdgfgchbjhgdhijhgbijchddegbgigdhbfjediegfebdgcdiiifjdaggabegafgchbjfijgeidacdjbjjhbedafigebfebiiadcdjjjagaibccaggcgdeaicbijahichchcddidgaidachiegddcaejejddiigfihfaifgdfddbfaidcjiaajifgjfdddhejiijhchecdbbjchhfdigdhadbeifcghghcchbfbacheijbcgejbhccabdccbfgahhfggjigdaccefjidhchjigjdhgcchigheehbcjgffigfjfdfbcgfghhaghdciacjfidgghgdcijcgeiecggbfbjihfdjjdifbjahgfgjjgjbjcdcghfaafbjjjjcbcidfgicbjedjdbegadiefdcicegjibicjeajcjcciaigadbgbcehfbbdjidccddbjegebaggjcgcjfjfafcbiecggdebfhbajeagifaeaieabbbddabiecdcdeeechhafachfcejggcbbbhcegjbbgccfhjiejhfehcefbadgjeffcjjidecgahfdfcchejijajebcjfcbbifihciibccgbcbjbbeahcihhddjhcaijdfabcejdhacfcgjiaceiaebdfgecfjchecdgfddcjbcjdheeeahbfjajdfdfbgbfiaddeebehjjjagjbeefcciahdgebfajbafiegjideahfjibiggajgejcedgccciehhefehdaejfefahbjieadhcaiahejeeegbfddbcfbdcheedadejeaejhhdachidbgbchcbgiiegghdiihagighdhjaaccheeebaagcjadfbjjcihdjfcchdjcjjebahighbcbggbbbhgibfffcjgjfdafifcjhbafigdiejajecafajhbeiiehdcjbhbbbbcffbdffhdgfjjiiihihdaeidjifdicjcgadgccfjihjjhagebibgjbbhhbjeddjjejidcchjidaaddbfihffigifhcecihcigjaehcfaffedbgbjajgdjfcfifcgdidcjccgieaiedcacgegebhiacicebegbjaidcjfggbcdgjhcfihgcibcccejbicigbccgigdhfaabgibigicddfbegbbhjeedbdgedcbbibgfgcahajfbgiheffdeidcjfbefejjhcafdjfjfiifadabgeifchfhjccicdfhghidefafcadiiibhhegdjhbfbddceeajhbcbhdhihbhjcdbghibciceghcejidcghcihhadibddficigbgfbijihcfgiddhedbdfaggcbebihhehaahicjfegffbefffcdbabececiacihaedbdddaddgjgejgdgafhaedbbfiahajcjdajadbcghhdejajhafjgjjhjbbdbgcacffjbcbiaciejbgjffjaabhjciibfdcecaffafifcihjdgafgiijedadhfhceiechebhfigaageadjhheafihhgachgcafeedahdiaehiheiffijecjahafadfejdbaafgcedacigfeibjffgbddbgcgicaeehggihgiidifhhigeihccafehacacdihbgddafcaggaifdcbgbeijfdddegdgjfcidbjhcfgeffbefdhbehagjahgbbhiicdcfijjifdibfadeaicebdjeddichdghhijbhiaedfeabebbagggafeaiahggjacjbhjdcgcgfjbcjgiidddhefcffacdafgdgbegfbggbdihgabagdcbfcfbebajiefbaacjiiggiiacaafcjecabibaagfaahaggbjadijjihgbhicjdjgjgahafiedjegdabecjaajaeegbcbefigbhahfhgcdiddchjgaacehgjdhaehbjbjiieaidefiajafdgbadgedabhiiffdhjeibgcagafddahhihfdejeaaafgaighdgaaabcadigcigbdadbedcefidjacjjhdbedfehijigchceifefgeifihccbegbcfgjgabcegdceiahbccajgejdadjdajgjjhgfjgahciiajjjijbgfffffjbbcgjbaedcjjbhgebfjgfgjjghhaiaajehbcaieeaedgfehaajifigffijefabaaebbcedbbjebbcdhceahcdgbdhgebifbcaghagfcbidgfeehadbfhggbfdbcciggjfeaijjccfceiaijafdfagjadahjeabfhccibhddcjieijgaghcjcjchdjfjgaadicghjgfajcabajbhecgajbiiaefbbjibfgjedhijachhfiecdbeedhadcdiihdhccjaaaigjdcecbfjadccaejjbhfbibceaachdcdgffhjfdichgffjgeajgjdbjfedgceehafjbfdbdjieceifbaicbbjgddajihegcaicbcfhfgjajjgfbbhhhdhefcfaghhfhcifdcaafiifdcgjjccajciijideeccjbegaahjehiggadfijdefbaidhebfcjibcchebidbbffdiecbfiebedcjhaehjbcgjcbicibchibbdbhghhdjifaghifefgdhcdjcabgggcfhchjadfcaedbjhihhhgejdbhfbhagaifabbfcdbiceaafifddhjaciehjdeigehiagaaebfifegdecegbccgecdcbajgadajfdgfbjdcbafijdhdbabgajfdiagagfdcdchbagfdeafehhifhcabfciechjfiagdebadjeahcadfcahaagacjiehahacejaccegfhghiggfibfbhfffidbahcijhfbfdcciaajgjjjjadjjbjdgcediahhhjgcjhfddejfjbibeaiebhgjbjgigbacdiihjgcbegdgeibihbfffccfgicgifajafdeafheiigddhjaiieibhdfidfbbdbgicajeeiecdidhaibfaefbhjfadbfaadbhafghdijdegchegfigaaaeajcjhjdfjgcadbhdibhfgdffbeeggjdjdcbigfgheddhhcghficdiedciighdgaidfgbchhabjegfjddhegigbcadedihcbfdgajdbjjiegbicbhhiedhagccagcbdhhbgbfihiagefhaiaaigiaijjdabhiecejcbciajefggaceheiiaecdechiaefdcijffdfgdchedbbdhciiadaebbdgdhccfgdiaggcgffaigadecbiecbdhfedaehhbaejaeidgjdfacehaaeicbifggjaacfgcjgfjhiaeehahdicbfidgahehchfigajcbafahhjbhihfhcgdhihbijidahfgfjeiiabhagdbgcdffhajcdchjdedeeabhgecfgcbfccabgjbhdjddfigbcfachhdebajeidhjadccheadfjdgjaagedahhjefidfdciheechciebgfghaihhdhgiieaijgbfdjghejeeiejchgbfjhijfbfdjhjbbhahcecdcjidgggfgbdjbdhgeacdgbfjbhbeeegdgceigjidjhbbfjaggbbbjfabfijcefbagbjdcdiigbghhgejhacjecahbbbicicedbigbfghbhgbdjgceiibijhgbjbejifhjcejdjhaeejeghedjhibihfffbjbgiedcafgebaadgccbabcgfcjgbigfgfjahcadibffgfdjhgbgjcbaficgcihiehghhgggejadfghhebhhdfgcgcaacdedjheehdbddacgiijaiaiebbjiifihajhgajbififdcijgfcbgieidadiefhfefchfbfjdadibgcecfbaejjhfchedcgjdeggfjbebiaihihccefgibdafgfddhbgeghhgdcdfceajfbfibeieehbhcgjiddghfgagchefbeaegfbajcihjbihbgcgfgfeaegebbhhfcgcfahjffifghhhbbaiiigejcjafigcjbadjefgafccajccjffhfgcidchabfbbfiedcgcdbaiaaebjcjjfdhjaicbhdcifcdbfhhgcfabijciedhiejeacjhfjchddcjgfibghijcdeehbjcgijgfdfaedbeiicbfjjecfhebdbhiiefcgcbcbjbhhbcgbdhfjejaecibgbagcjjeffjbcedifbdddifahahgebceacbjjgacgjbhhchgecbjhiegebdhadcieegjfgaigfaceidiabhifghbjihjfjgjjafabjcigchjijadgiaibghfhgjjfdffbfagaededjiifijeggaffdbgidhacbeheajjeiaeigbihcajcbajchhdgdccbccfecejbbfhcaghbagffjcjicdcachjggdcdjhhigbbffhhbjccjbfgdhieaadfhgfhabcjfhhafiacbeaaicigcdhecchiebcaajaiedbghffiacijfebeahgchhheecaejdcibefbjheidhffefbgfieibaffgidifabghbifhfbcecccjihijecffhjaggdbbfffejfeihdjdhiidbaehaechhdfidggjicfahjiigfjgahjebadhjbjbjcacjehfjjfhecffighjfdjdchjdijbcibddbgdeffhjaccigcfbeihciaffifggbdabbbgiiecfcjhgedajghfbhcheecejegdeheicbdiieecdfcidicbhhdgddcfeiaajefjifjghgdjfgcijjfhihiigicdcjagfdabcaehajeaebcchbifbgcdbabcjhbjcegihefafchdgeabgdcccjdgidbibdfaifiejjhehdfaecifhghhjacacaijeajcehbgcjadcgigddifidfghgcbecaeidcfagjcbbjaaccdbacgbjcciadceigfadajgbadcchhgbjbccedeejbifjjidcjbaegcdgidigffcgedaajjffhhajeiiiffcfgjbfdhiccddieideehejccjefeidfeebiighabiehdehdfggbjcdecjfcffjbggbgbfcfdahccigbbibejbjhjcjdcijgebfiafiibgcafecegccjfcefddeifheddeiahcbicbafgcbhbgcgcijjbacdigicfghifbaddjheeiiicdfjeeejhaibigcicgecgechbhbffhfgbdbgjdcdhijibahbggagejccjbfhfhdcjcdbgbehigbbfbcfcdaeadggjgaadjhgeicefhahiafbhgjaajeibbafhbeifgfcgdbhjcbbjbiifhecgfcbjdhjhhgdjdajeeebghgjcbeegbciddchihcecjbdebjiaabaiidccjccchecdeeffccgjajfihibiaagihbjbghjfjdfbfeccgdgebdhbefhfifjgajabjdbchfjiiaihecibajgicfijbgfebbeghdjfigfbiadefccfcgafabgbcjgjjfdahhjihafibcgacdcejfiffihbegcggadeegfigjhfcgdaidaefaicgddfcdibdbifbjbbddiahghagjefdaegiciihheegjfhgebhfiddjaaajgagcafgahgagjijhfagiabjiiicdfjejebeegbgbbaifeaeghgeejajfhibgggjdhdbfedeadciheggjbdahegchibffdbhdfbhgcddebhafjicheghgcaajgjjebcceahabgigbgadaeiejfhfcgjfciidgfafibijjiadihffdciiaeegacjiiiijfdhbhfbbfabigigehijeiidieeedaahgcgeeicgaccffcaabhgbjgegibggbcbhebgcahgicfggghaigdehgjachfihcbaifjgbafjdjfahcecehcegbaedidggadbjajjfeeedidgiaeffhcaagabdbhhfgbjafedaajjffdagejcfgfgbdbijcdaiaebcafjccicjgcdbiehcbieeaeijdfiiaecceiijjdcbgieggciiceeeahgjacffhcedhaajccidfjafdigbbgcdchibeijhccdccciffjedcediehcfhffiageeffdcgfihjbijghaififjhgheabejghjgdjabhjgbigffbabicfbbgadhbccijfijgjfihfgjeccjjbdagjgchdiggefdhhcafaajiccdhidjgggadfehhgecfgdgaghhbjdhcdbabhjdcigbedcbgbhgdahhbebaifeecjhcjcgfcjehfghigjjagaaceccjcifeibbbcjdcjbdiibdgaacaeedeccgabecbeigdfhjajdbaibffjdchedcbbgbbaaffeaifejdeefcejdgdhhjicbdcdjigjccfjccbhefbbggajeahcidfajaifcggedbihdcacbbjcecdhbigjdifdbdhdbafeifagefhjjbifeaagcjicecaagehbcijegjediacdhjagcgdjihihicefdhjcadcigicfadggjfjggbcbehgejfjgbeahbjiabcgehficcagigefjbjaeiddjjdaigcbbgiiebhfhbhbcghgcefgjgjeaabghhgjdhicedfcgfdiajbedcbcfeiaddhagaaccdciibebadgbieagdgefgbgeeagefaehcbeichhfaebgbddgadcbghcgeiccjcciaifbegegfjajjdjdcgbhcjcjgihcjajehhbhjjdighdcagafffgehbbedbaidegghfgigidhijcbdgdcadgcefebjagdhjfeabbcjbfdgjgcdjfgfjdffajeaeddbfbigddjibcehafiedabaecdedfafacbgdbjiigbdefabdhdcbjbefaeedhchbecjifgaggcjjafchdegfdfgjfjjjjcfaiaddibebebfbbebdiaacgjafcjjhfhhfgbdbebbgajcffjcgabcjfeehgadhcdhbifeceiheiahajchhchcicbjahbbbjidfdahhjcdhibbddhbcbddjcchfdicgbaheabjefjgdjeddeiigjfccgdajdfiibbdjgdfehbhhcdejjfdjacffijhbaihfjddejafbfaedfefdecidjacdhheefdcdbcfgibbg";
    //cout << s.canConstruct("a", "b") <<endl;
    //cout << s.canConstruct("aa", "ab") <<endl;
    //cout << s.canConstruct("aa", "aab") <<endl;
    cout << s.canConstruct(str1,str2) << endl;
    return 0;
}