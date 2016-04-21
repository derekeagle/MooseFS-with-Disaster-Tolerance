#ifndef _SF_COMMON_H_ 
#define _SF_COMMON_H_ 

#include <sys/types.h>
#include <stdint.h> 


/*
 sfflag_t                      �ļ�ͬ��ģ�飬��ʶ��������ȫ��������
 SF_FULL                       �������������Ժ��ڵ��ýӿ�
 SF_FAIL                       ʧ��
 SF_GROW                       ��������
 SF_ALL                        ȫ������
 SF_ALL_NOTIME                 ȫ��������ʱ�����
 SF_ALL_SRCPATH_ERR            ȫ������srcpath��������
 SF_ALL_DSTPATH_ERR            ȫ������dstpath��������
 SF_FLAG_ERR                   flag��������
 SF_GROW_TABLE_ERR             ��������ʱ��tableΪNULL�����µĴ���
 SF_GROW_MAXNUM_ERR            ��������ʱ��max_numС�ڵ���0�����µĴ���
 SF_GROW_SRCPATH_ERR           ��������ʱ��srcpath����
 SF_GROW_DSTPATH_ERR           ��������ʱ��dstpath����
 SF_GROW_EQPATH_ERR            ��������ʱ��eqpath����
 SF_ALL_STTIMER_ERR            ȫ������ʱ��st_timerС��0�����µĴ���
 SF_ALL_EDTIMER_ERR            ȫ������ʱ��ed_timerС��0�����µĴ���
 SF_ENTER_PARAMETER_SAVE_ERR   copy_run�ӿڵ��ã�ʱ�򱣴������ʧ��
 SF_POOL_INIT_ERR              �̳߳س�ʼ��ʧ��
*/
typedef char sfflag_t;
#define SF_ALL                 '0' 
#define SF_ALL_NOTIME          '5'
#define SF_GROW                '1' 
#define SF_FULL                '3'
#define SF_FAIL                '4'
#define SF_ALL_SRCPATH_ERR     '2'
#define SF_FLAG_ERR            '6'
#define SF_GROW_TABLE_ERR      '7'
#define SF_GROW_MAXNUM_ERR     '8'
#define SF_ALL_STTIMER_ERR     '9'
#define SF_ALL_EDTIMER_ERR     'a'
#define SF_ENTER_PARAMETER_SAVE_ERR 'b'
#define SF_POOL_INIT_ERR       'c'
#define SF_ALL_DSTPATH_ERR     'd'
#define SF_GROW_SRCPATH_ERR    'f'
#define SF_GROW_DSTPATH_ERR    'g'
#define SF_GROW_EQPATH_ERR     'h'


/*
 sign_t                       �ɹ����������
 SIGN_FAIL                    �ɹ�                     
 SIGN_SUCCESS                 ʧ��
 SIGN_PARAMETER_TYPE_ERR      Table_From_Grow��Աtype����
 SIGN_PARAMETER_OPERNAME_ERR  Table_From_Grow��Աoperationname����
 SIGN_PARAMETER_FILEPATH_ERR  Table_From_Grow��Աfilepath�Ǿ���·��
*/
typedef int sign_t;
#define SIGN_FAIL                     0
#define SIGN_SUCCESS                  1
#define SIGN_PARAMETER_TYPE_ERR       2
#define SIGN_PARAMETER_OPERNAME_ERR   3
#define SIGN_PARAMETER_FILEPATH_ERR   4



#define MAX_PATH_SIZE               (4096)
/*
#define MAX_PATH_SIZE               (31)
*/
#define MAX_PATH_BUF                ( MAX_PATH_SIZE + 1)


#define MAX_OPER_LENGTH             (16)

/*
  CONFIG_IS_HIDE         Config�ṹʽ�Լ������Ƿ�Ҫ
  TEST_SYSLOG_INFO_USER  ��ӡsyslog��Ϣ������ʹ��
  DUG_SIGN_USER sign_operchnglog_from_mapfile������ͨ���취������ʹ��

  TEST_ALL_DY_THREADNUM  ����ȫ����̬���Ӽ����߳���Ŀ 0����,���ڲ���   1��������
  TEST_GROW_DY_THREADNUM ����������̬���Ӽ����߳���Ŀ 0����,���ڲ���   1��������
  IS_ALL_CMD              �Ƿ��ȫ��������������
  TEST_POOLFILE_HAS_MAIN  pool.c�ļ������Ƿ������ʹ��main����
  DEBUG_PRINTF_SYSLOG_TEST �Բ�ʱ��ʹ���Ƿ�ʹ��syslog/printf��ӡһЩ��ʾ��Ϣ

*/

#define CONFIG_IS_HIDE                       0
#define TEST_SYSLOG_INFO_USER                1
#define DUG_SIGN_USER                        0

#define TEST_ALL_DY_THREADNUM                1
#define TEST_GROW_DY_THREADNUM               1
#define IS_ALL_CMD                           1
#define TEST_POOLFILE_HAS_MAIN               0
#define DEBUG_PRINTF_SYSLOG_TEST             1



/*  define for grow  */

#define DISPLAY_DEBUG_SYSLOG_GROW 0


typedef struct operationtable {
    uint32_t inode;
    uint32_t parentinode;
    
    uint8_t type;  //'d' or 'f'
    uint8_t flag;  // oper  time < 5;
    
    uint32_t lasttime;

    uint8_t operationname[MAX_OPER_LENGTH]; 
    uint8_t filepath[MAX_PATH_SIZE];
    
    struct operationtable *next;
    //and so on
} operationtable,Table_From_Grow;


#endif
