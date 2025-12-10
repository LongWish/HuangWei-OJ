#include <stdio.h>
#include <string.h>

char A[10010], B[10010], NA[10010], NB[10010];

enum{P,N,NEG,DOT,I,END,FS,FE,FJ,IL,FL,ISZ,W,CNT};
int aa[CNT], bb[CNT];

int main(){

	while(scanf("%s %s",A,B)==2){

		aa[P]=0; aa[N]=strlen(A); aa[NEG]=0; aa[DOT]=-1;
		if(A[0]=='+'||A[0]=='-'){ if(A[0]=='-') aa[NEG]=1; aa[P]++; }

		for(int t=aa[P]; t<aa[N]; t++) if(A[t]=='.'){ aa[DOT]=t; break; }

		aa[END] = (aa[DOT]==-1? aa[N] : aa[DOT]);
		aa[I]=aa[P];
		while(aa[I]<aa[END] && A[aa[I]]=='0') aa[I]++;
		aa[IL] = aa[END] - aa[I];

		aa[FS] = (aa[DOT]==-1? aa[N] : aa[DOT]+1);
		aa[FE] = aa[N];
		aa[FJ] = aa[FE]-1;
		while(aa[DOT]!=-1 && aa[FJ]>=aa[FS] && A[aa[FJ]]=='0') aa[FJ]--;
		aa[FL] = (aa[DOT]==-1? 0 : (aa[FJ]>=aa[FS]? aa[FJ]-aa[FS]+1 : 0));

		aa[ISZ]=0;
		if(aa[DOT]==-1){
			aa[ISZ]=1;
			for(int t=aa[P]; t<aa[N]; t++) if(A[t]!='0'){ aa[ISZ]=0; break; }
		}else{
			int allz=1;
			for(int t=aa[P]; t<aa[DOT]; t++) if(A[t]!='0'){ allz=0; break; }
			if(allz){ for(int t=aa[FS]; t<aa[FE]; t++) if(A[t]!='0'){ allz=0; break; } if(allz) aa[ISZ]=1; }
		}

		aa[W]=0;
		if(aa[ISZ]){ NA[aa[W]++]='0'; NA[aa[W]]=0; }
		else{
			if(aa[NEG]) NA[aa[W]++]='-';
			if(aa[IL]>0) for(int t=0;t<aa[IL];t++) NA[aa[W]++]=A[aa[I]+t]; else NA[aa[W]++]='0';
			if(aa[FL]>0){ NA[aa[W]++]='.'; for(int t=0;t<aa[FL];t++) NA[aa[W]++]=A[aa[FS]+t]; }
			NA[aa[W]]=0;
		}

		bb[P]=0; bb[N]=strlen(B); bb[NEG]=0; bb[DOT]=-1;
		if(B[0]=='+'||B[0]=='-'){ if(B[0]=='-') bb[NEG]=1; bb[P]++; }

		for(int t=bb[P]; t<bb[N]; t++) if(B[t]=='.'){ bb[DOT]=t; break; }

		bb[END] = (bb[DOT]==-1? bb[N] : bb[DOT]);
		bb[I]=bb[P];
		while(bb[I]<bb[END] && B[bb[I]]=='0') bb[I]++;
		bb[IL] = bb[END] - bb[I];

		bb[FS] = (bb[DOT]==-1? bb[N] : bb[DOT]+1);
		bb[FE] = bb[N];
		bb[FJ] = bb[FE]-1;
		while(bb[DOT]!=-1 && bb[FJ]>=bb[FS] && B[bb[FJ]]=='0') bb[FJ]--;
		bb[FL] = (bb[DOT]==-1? 0 : (bb[FJ]>=bb[FS]? bb[FJ]-bb[FS]+1 : 0));

		bb[ISZ]=0;
		if(bb[DOT]==-1){
			bb[ISZ]=1;
			for(int t=bb[P]; t<bb[N]; t++) if(B[t]!='0'){ bb[ISZ]=0; break; }
		}else{
			int allz=1;
			for(int t=bb[P]; t<bb[DOT]; t++) if(B[t]!='0'){ allz=0; break; }
			if(allz){ for(int t=bb[FS]; t<bb[FE]; t++) if(B[t]!='0'){ allz=0; break; } if(allz) bb[ISZ]=1; }
		}

		bb[W]=0;
		if(bb[ISZ]){ NB[bb[W]++]='0'; NB[bb[W]]=0; }
		else{
			if(bb[NEG]) NB[bb[W]++]='-';
			if(bb[IL]>0) for(int t=0;t<bb[IL];t++) NB[bb[W]++]=B[bb[I]+t]; else NB[bb[W]++]='0';
			if(bb[FL]>0){ NB[bb[W]++]='.'; for(int t=0;t<bb[FL];t++) NB[bb[W]++]=B[bb[FS]+t]; }
			NB[bb[W]]=0;
		}

		if(strcmp(NA,NB)==0) puts("YES"); else puts("NO");
	}

	return 0;
}
