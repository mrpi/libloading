#pragma once

#include <libloading/Library.hpp>
#include <sql.h>

class Odbc : libloading::Library
{
public:
   Odbc(libloading::ILibraryLoader& loader)
    : libloading::Library(loader, {/*on WIN32*/"odbc32", /*for unix odbc*/"odbc"})
   {}

   LIBL_STDCALL(SQLAllocConnect, SQLRETURN(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle));
   LIBL_STDCALL(SQLAllocEnv, SQLRETURN(SQLHENV *EnvironmentHandle));
   LIBL_STDCALL(SQLAllocHandle, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE InputHandle, SQLHANDLE *OutputHandle));
   LIBL_STDCALL(SQLAllocStmt, SQLRETURN(SQLHDBC ConnectionHandle, SQLHSTMT *StatementHandle));
   LIBL_STDCALL(SQLBindCol, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType, SQLPOINTER TargetValue, SQLLEN BufferLength, SQLLEN *StrLen_or_Ind));
   LIBL_STDCALL(SQLBindParam, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType, SQLSMALLINT ParameterType, SQLULEN LengthPrecision, SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue, SQLLEN *StrLen_or_Ind));
   LIBL_STDCALL(SQLCancel, SQLRETURN(SQLHSTMT StatementHandle));
#if (ODBCVER >= 0x0380)
   //LIBL_STDCALL(SQLCancelHandle, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE InputHandle));
#endif
   LIBL_STDCALL(SQLCloseCursor, SQLRETURN(SQLHSTMT StatementHandle));
   LIBL_STDCALL(SQLColAttribute, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier, SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLLEN *NumericAttribute));
   LIBL_STDCALL(SQLColumns, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1, SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName, SQLSMALLINT NameLength3, SQLCHAR *ColumnName, SQLSMALLINT NameLength4));
   LIBL_STDCALL(SQLConnect, SQLRETURN(SQLHDBC ConnectionHandle, SQLCHAR *ServerName, SQLSMALLINT NameLength1, SQLCHAR *UserName, SQLSMALLINT NameLength2, SQLCHAR *Authentication, SQLSMALLINT NameLength3));
   LIBL_STDCALL(SQLCopyDesc, SQLRETURN(SQLHDESC SourceDescHandle, SQLHDESC TargetDescHandle));
   LIBL_STDCALL(SQLDataSources, SQLRETURN(SQLHENV EnvironmentHandle, SQLUSMALLINT Direction, SQLCHAR *ServerName, SQLSMALLINT BufferLength1, SQLSMALLINT *NameLength1, SQLCHAR *Description, SQLSMALLINT BufferLength2, SQLSMALLINT *NameLength2));
   LIBL_STDCALL(SQLDescribeCol, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLCHAR *ColumnName, SQLSMALLINT BufferLength, SQLSMALLINT *NameLength, SQLSMALLINT *DataType, SQLULEN *ColumnSize, SQLSMALLINT *DecimalDigits, SQLSMALLINT *Nullable));
   LIBL_STDCALL(SQLDisconnect, SQLRETURN(SQLHDBC ConnectionHandle));
   LIBL_STDCALL(SQLEndTran, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT CompletionType));
   LIBL_STDCALL(SQLError, SQLRETURN(SQLHENV EnvironmentHandle, SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle, SQLCHAR *Sqlstate, SQLINTEGER *NativeError, SQLCHAR *MessageText, SQLSMALLINT BufferLength, SQLSMALLINT *TextLength));
   LIBL_STDCALL(SQLExecDirect, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength));
   LIBL_STDCALL(SQLExecute, SQLRETURN(SQLHSTMT StatementHandle));
   LIBL_STDCALL(SQLFetch, SQLRETURN(SQLHSTMT StatementHandle));
   LIBL_STDCALL(SQLFetchScroll, SQLRETURN(SQLHSTMT StatementHandle, SQLSMALLINT FetchOrientation, SQLLEN FetchOffset));
   LIBL_STDCALL(SQLFreeConnect, SQLRETURN(SQLHDBC ConnectionHandle));
   LIBL_STDCALL(SQLFreeEnv, SQLRETURN(SQLHENV EnvironmentHandle));
   LIBL_STDCALL(SQLFreeHandle, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE Handle));
   LIBL_STDCALL(SQLFreeStmt, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT Option));
   LIBL_STDCALL(SQLGetConnectAttr, SQLRETURN(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength));
   LIBL_STDCALL(SQLGetConnectOption, SQLRETURN(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLPOINTER Value));
   LIBL_STDCALL(SQLGetCursorName, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *CursorName, SQLSMALLINT BufferLength, SQLSMALLINT *NameLength));
   LIBL_STDCALL(SQLGetData, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType, SQLPOINTER TargetValue, SQLLEN BufferLength, SQLLEN *StrLen_or_Ind));
   LIBL_STDCALL(SQLGetDescRec, SQLRETURN(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLCHAR *Name, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength, SQLSMALLINT *Type, SQLSMALLINT *SubType, SQLLEN *Length, SQLSMALLINT *Precision, SQLSMALLINT *Scale, SQLSMALLINT *Nullable));
   LIBL_STDCALL(SQLGetDiagField, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier, SQLPOINTER DiagInfo, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength));
   LIBL_STDCALL(SQLGetDiagRec, SQLRETURN(SQLSMALLINT HandleType, SQLHANDLE Handle, SQLSMALLINT RecNumber, SQLCHAR *Sqlstate, SQLINTEGER *NativeError, SQLCHAR *MessageText, SQLSMALLINT BufferLength, SQLSMALLINT *TextLength));
   LIBL_STDCALL(SQLGetEnvAttr, SQLRETURN(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength));
   LIBL_STDCALL(SQLGetFunctions, SQLRETURN(SQLHDBC ConnectionHandle, SQLUSMALLINT FunctionId, SQLUSMALLINT *Supported));
   LIBL_STDCALL(SQLGetInfo, SQLRETURN(SQLHDBC ConnectionHandle, SQLUSMALLINT InfoType, SQLPOINTER InfoValue, SQLSMALLINT BufferLength, SQLSMALLINT *StringLength));
   LIBL_STDCALL(SQLGetStmtAttr, SQLRETURN(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER BufferLength, SQLINTEGER *StringLength));
   LIBL_STDCALL(SQLGetStmtOption, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT Option, SQLPOINTER Value));
   LIBL_STDCALL(SQLGetTypeInfo, SQLRETURN(SQLHSTMT StatementHandle, SQLSMALLINT DataType));
   LIBL_STDCALL(SQLNumResultCols, SQLRETURN(SQLHSTMT StatementHandle, SQLSMALLINT *ColumnCount));
   LIBL_STDCALL(SQLParamData, SQLRETURN(SQLHSTMT StatementHandle, SQLPOINTER *Value));
   LIBL_STDCALL(SQLPrepare, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *StatementText, SQLINTEGER TextLength));
   LIBL_STDCALL(SQLPutData, SQLRETURN(SQLHSTMT StatementHandle, SQLPOINTER Data, SQLLEN StrLen_or_Ind));
   LIBL_STDCALL(SQLRowCount, SQLRETURN(SQLHSTMT StatementHandle, SQLLEN *RowCount));
   LIBL_STDCALL(SQLSetConnectAttr, SQLRETURN(SQLHDBC ConnectionHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER StringLength));
   LIBL_STDCALL(SQLSetConnectOption, SQLRETURN(SQLHDBC ConnectionHandle, SQLUSMALLINT Option, SQLULEN Value));
   LIBL_STDCALL(SQLSetCursorName, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *CursorName, SQLSMALLINT NameLength));
   LIBL_STDCALL(SQLSetDescField, SQLRETURN(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier, SQLPOINTER Value, SQLINTEGER BufferLength));
   LIBL_STDCALL(SQLSetDescRec, SQLRETURN(SQLHDESC DescriptorHandle, SQLSMALLINT RecNumber, SQLSMALLINT Type, SQLSMALLINT SubType, SQLLEN Length, SQLSMALLINT Precision, SQLSMALLINT Scale, SQLPOINTER Data, SQLLEN *StringLength, SQLLEN *Indicator));
   LIBL_STDCALL(SQLSetEnvAttr, SQLRETURN(SQLHENV EnvironmentHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER StringLength));
   LIBL_STDCALL(SQLSetParam, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT ParameterNumber, SQLSMALLINT ValueType, SQLSMALLINT ParameterType, SQLULEN LengthPrecision, SQLSMALLINT ParameterScale, SQLPOINTER ParameterValue, SQLLEN *StrLen_or_Ind));
   LIBL_STDCALL(SQLSetStmtAttr, SQLRETURN(SQLHSTMT StatementHandle, SQLINTEGER Attribute, SQLPOINTER Value, SQLINTEGER StringLength));
   LIBL_STDCALL(SQLSetStmtOption, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT Option, SQLULEN Value));
   LIBL_STDCALL(SQLSpecialColumns, SQLRETURN(SQLHSTMT StatementHandle, SQLUSMALLINT IdentifierType, SQLCHAR *CatalogName, SQLSMALLINT NameLength1, SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName, SQLSMALLINT NameLength3, SQLUSMALLINT Scope, SQLUSMALLINT Nullable));
   LIBL_STDCALL(SQLStatistics, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1, SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName, SQLSMALLINT NameLength3, SQLUSMALLINT Unique, SQLUSMALLINT Reserved));
   LIBL_STDCALL(SQLTables, SQLRETURN(SQLHSTMT StatementHandle, SQLCHAR *CatalogName, SQLSMALLINT NameLength1, SQLCHAR *SchemaName, SQLSMALLINT NameLength2, SQLCHAR *TableName, SQLSMALLINT NameLength3, SQLCHAR *TableType, SQLSMALLINT NameLength4));
   LIBL_STDCALL(SQLTransact, SQLRETURN(SQLHENV EnvironmentHandle, SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType));
};
