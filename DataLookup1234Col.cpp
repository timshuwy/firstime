/*DataLookup1234Col - very similar to DataLookup, except you can specify UP TO 4 columns to search as well as the values to search for.*/
/*
	DataLookup1234Col(LookupTblID,ReturnColumn,Field1,Index1,Field2,Index2,Field3,Index3,Field4,Index4)
	sample use would be:
	MyValue = DataLookup1234Col("MyTableField","Description","Question","Color","Answer","Red","","","","")
	The above would search the lookup table "MyTableField" and would return the DESCRIPTION of the item where the QUESTION column = COLOR and the ANSWER column = RED, and we dont search any other columns


 	There are TEN parameters that are passed to this:
 		LookupTblID - the lookup table id you want to look in
		ReturnColumn - the Field of the column/value to return
 		Field1 - the Field of the column in the above table - IF BLANK, ignores this search
 		Index1 - the value to search for in the above column 1
 		Field2 - the Field of the column in the above table - IF BLANK, ignores this search
 		Index2 - the value to search for in the above column 2
 		Field3 - the Field of the column in the above table - IF BLANK, ignores this search
 		Index3 - the value to search for in the above column 3
 		Field4 - the Field of the column in the above table - IF BLANK, ignores this search
 		Index4 - the value to search for in the above column 4


	This will RETURN the first falue that is found where the four columns specified contain the four values specified.

*/

  return (from ReturnCol in Db.PcLookupTblValues
    join Lookup1 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { Lookup1.Company, Lookup1.RowNum, Lookup1.LookupTblID }
    join Lookup2 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { Lookup2.Company, Lookup2.RowNum, Lookup2.LookupTblID }
    join Lookup3 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { Lookup3.Company, Lookup3.RowNum, Lookup3.LookupTblID }
    join Lookup4 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { Lookup4.Company, Lookup4.RowNum, Lookup4.LookupTblID }
    where
       (Field1 == "" || (Lookup1.ColName == Field1 && Lookup1.DataValue == Index1))
    && (Field2 == "" || (Lookup2.ColName == Field2 && Lookup2.DataValue == Index2))
    && (Field3 == "" || (Lookup3.ColName == Field3 && Lookup3.DataValue == Index3))
    && (Field4 == "" || (Lookup4.ColName == Field4 && Lookup4.DataValue == Index4))
    && (ReturnCol.LookupTblID == LookupTblID && ReturnCol.ColName == ReturnColumn)
    select ReturnCol.DataValue ).FirstOrDefault() + "";
