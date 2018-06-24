/*DataLookupTwoCol - very similar to DataLookup, except you can specify the TWO columns to search as well as the values to search for.*/
/*

	sample use would be:
	MyValue = DataLookupTwoCol("MyTableName","Question","Color","Answer","Red","Description")
	The above would search the lookup table "MyTableName" and would return the DESCRIPTION of the item where the QUESTION column = COLOR and the ANSWER column = RED

 	There are SIX parameters that are passed to this:
 		LookupTblID - the lookup table id you want to look in
 		Column1Name - the name of the column in the above table
 		Column1SearchValue - the value to search for in the above column 1
 		Column2Name - the name of the column in the above table
 		Column2SearchValue - the value to search for in the above column 2
 		ReturnColumnName - the name of the column/value to return

	This will RETURN the first falue that is found where the two columns specified contain the two values specified.

*/

  return (from ReturnCol in Db.PcLookupTblValues
    join SearchCol1 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { SearchCol1.Company, SearchCol1.RowNum, SearchCol1.LookupTblID }
    join SearchCol2 in Db.PcLookupTblValues on new { ReturnCol.Company, ReturnCol.RowNum, ReturnCol.LookupTblID } equals new { SearchCol2.Company, SearchCol2.RowNum, SearchCol2.LookupTblID }
    where
       SearchCol1.ColName == Column1Name
    && SearchCol1.DataValue == Column1SearchValue
    && SearchCol2.ColName == Column2Name
    && SearchCol2.DataValue == Column2SearchValue
    && ReturnCol.LookupTblID == LookupTblID
    && ReturnCol.ColName == ReturnColumnName
    select ReturnCol.DataValue ).FirstOrDefault() + "";




