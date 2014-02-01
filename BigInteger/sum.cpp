#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string sum(string a, string b){
    int len_a = a.size();
    int len_b = b.size();

    if(!len_a &&  len_b) return b;
    if(!len_b &&  len_a) return a;

    string tmp;
    if(len_b > len_a){
        int t = len_a;
        len_a = len_b;
        len_b = t;
        tmp = a;
        a = b;
        b = tmp;
    }
    tmp = a;
    int j = len_a;
    tmp[j--] = '\0';
    len_a--;
    len_b--;
    
    short carry = 0;
    while(len_a >= 0){
        int sum = 0;
        sum += (int)a[len_a--] - 48;
        if(len_b >= 0) sum += (int)b[len_b--] - 48;

        sum += carry;
        if(sum < 10){
            tmp[j--] = sum + 48;
            carry = 0;
        }else{ 
            tmp[j--] = (sum - 10) + 48;
            carry = 1;
        }
    }
    if(carry) return (char)(carry + 48) + tmp;
    else return tmp;
}

int main(){
    string a = "1481634108287694181368579508302126568685726726556032773295369980863163021276410929545762121396615088628602215467919127826317623934869858296012527626226395691654792705601414580496395471161438406455381021970581073744382665834855450983365600678807851693352286286949131991852608387157958194103347218491885134054441098886039667799905486720012239583815444400994244644457765694245781901295276116068163106010064757051614312351255165240293295167735450958637701613845479307453424330895872016930986813597747374171991096785237645628407640536269472427611318746932562185771602376571761375729604794245377394102970534041319352784161483545386781465240055296381093867131987331003920251472538262172131026640199027709909634658902103553862659794710409253895888298862771328657849670354552802402321838814703369306462269123194052986732519560039646415524087854478028695895215252296636839489506528276661603942749037110797652402104708668586376759005777396513558832806521681484282062474005144397002861109211801942206896393757663352583630451909283449925741707976029534255624";

    string b = "2397334346100631452333336800023778743396400988090212332865227234032387117767626167465060795065595580850691237390963845987165478074085124644348902530685083246709423858342692329718110162972268152200857232686119638781547238020078362945470777668711057069618425746387920931255084621360135655698456629322111614827324455767748623844363426260372374195153577101298837831208580530677289982029527164306876024342838547454228388796380077029917639469963653048076473269452943584037848773158456736367057460079075603072996653089318046279296240100777360367200040226807430924334616931577257195085793060133817911514540227011756335999604550121968663793604830945238116686325506344893928776515696088851468818023735825546502317562957459506612704850760351077006532507519813600498603205937022956740021970327599548184626715032015801445754074519753924901317605013561516613650173445818028242577356369143977719495739428130191089993769093308407443558168431535751910046557480949313497996285124526992631353143367314930548703966553707195171094152730704138121243470432644848607501";

    string c = "3878968454388325633701916308325905312082127714646245106160597214895550139044037097010822916462210669479293452858882973813483102008954982940361430156911478938364216563944106910214505634133706558656238254656700712525929903854933813928836378347518908762970712033337052923107693008518093849801803847813996748881765554653788291644268912980384613778969021502293082475666346224923071883324803280375039130352903304505842701147635242270210934637699104006714174883298422891491273104054328753298044273676822977244987749874555691907703880637046832794811358973739993110106219308149018570815397854379195305617510761053075688783766033667355445258844886241619210553457493675897849027988234351023599844663934853256411952221859563060475364645470760330902420806382584929156452876291575759142343809142302917491088984155209854432486594079793571316841692868039545309545388698114665082066862897420639323438488465240988742395873801976993820317174208932265468879364002630797780058759129671389634214252579116872755600360311370547754724604639987588046985178408674382863125";

    /**
     * Compare the result of the sum a + b with C wich is the result.
     * the numbers: a,b,c are the fibonacci number for the numbers 4998, 4999 and 5000
     * the result is as follows:
     *
     * 1 -> succes
     * 0 -> failure not are the same the sum(a,b) with c
     */
    cout << (sum(a, b).compare(c) == 0);
}