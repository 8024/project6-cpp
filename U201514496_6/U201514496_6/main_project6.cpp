#include<stdio.h>
#include<iostream>
#include"QUEUE.h"

using namespace std;


int main(int agrc, char* agrv[]){
	int get_num = NULL;
	int num_cnt = 3;
	int lost_num = NULL;
	int sign_tran = 0;

	char filename[20] = "U201514496_6.txt";
	FILE *fp = fopen(filename, "w+");

	get_num = atoi(agrv[2]);
	fprintf(fp, "%c  %d  ", 'S', get_num);
	if (!get_num) {
		fprintf(fp, "%c", 'E');
		fclose(fp);
		cout << "the length of queue is 0,input error!" << endl;
		return 0;
	}
	QUEUE  queue(get_num);		//	创建新的队列
	QUEUE *pqueue = &queue;
	if (true == queue.m_bWrong) {
		cout << "Errors!" << endl;
		fprintf(fp, "%c", 'E');
		fclose(fp);
		return 0;
	}

	while (num_cnt < agrc) {
		if (!strcmp("-I", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'I');
			++num_cnt;
			while ((strcmp("-I", agrv[num_cnt]) && strcmp("-O", agrv[num_cnt]) && strcmp("-A", agrv[num_cnt]) && strcmp("-C", agrv[num_cnt]) && strcmp("-N", agrv[num_cnt]) && strcmp("-G", agrv[num_cnt])) && (num_cnt < agrc - 1)) {
				get_num = atoi(agrv[num_cnt]);
				pqueue->operator<<(get_num);
				if (pqueue->m_bWrong == true) {
					cout << "Error!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				++num_cnt;
			}
			if (num_cnt == agrc - 1) {
				get_num = atoi(agrv[num_cnt]);
				pqueue->operator<<(get_num);
				if (pqueue->m_bWrong == true) {
					cout << "Error!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				++num_cnt;
			}
			pqueue->print(fp);

		}
		else if (!strcmp("-A", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'A');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			QUEUE *pqueue_new_A = new QUEUE(get_num);
			pqueue_new_A->operator=(*pqueue);
			if (sign_tran) { delete pqueue; }
			if (pqueue_new_A->m_bWrong == true) {
				cout << "Error!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pqueue = pqueue_new_A;
			pqueue->print(fp);
			sign_tran = 1;
			++num_cnt;
		}
		else if (!strcmp("-C", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'C');
			QUEUE* pqueue_new_C = new QUEUE(*pqueue);
			if (sign_tran) { delete pqueue; }
			if (true == pqueue_new_C->m_bWrong) {
				cout << "Error!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pqueue = pqueue_new_C;
			pqueue->print(fp);
			sign_tran = 1;

			++num_cnt;
		}
		else if (!strcmp("-N", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'N');
			fprintf(fp, "%d  ", pqueue->operator int());
			++num_cnt;
		}
		else if (!strcmp("-G", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'G');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			if ((get_num >= pqueue->operator int()) || get_num<0) {
				cout << "Errors!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			fprintf(fp, "%d  ", pqueue->operator[](get_num));
			++num_cnt;
		}
		else if (!strcmp("-O", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'O');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			for (; get_num > 0; get_num--) {
				pqueue->operator >> (lost_num);
				if (true == pqueue->m_bWrong) {
					cout << "Errors" << endl;
					fprintf(fp, "%c  ", 'E');
					fclose(fp);
					return 0;
				}
			}
			pqueue->print(fp);
			++num_cnt;
		}
		else {
			cout << "the input is wrong!" << endl;
			fclose(fp);
			return 0;
		}
	}
	if (sign_tran) { delete pqueue; }
	cout << "the operations are done!" << endl;
	fclose(fp);

	return 0;
}