#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "IntegerSequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L1P2
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		// -----------------------------------------------------------------------------------
		// Queue1()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------
		
		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Sequence1();");
			Logger::WriteMessage(L"\toutgoing: q1 = <>");

			// Verify ensures: self = <>
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		
		}//endConstructorV1

		 // -----------------------------------------------------------------------------------
		 // Clear
		 // -----------------------------------------------------------------------------------
		 //! clears self
		 // -----------------------------------------------------------------------------------

		TEST_METHOD(UT02ClearV1)
		{
			IntegerSequence s1;
			Text x1;

			
			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Execute operation: clear
			s1.clear();

			// Verify parameter mode clears: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		}//End ClearV1
		
		TEST_METHOD(UT02ClearV2)
		{
			IntegerSequence s1;
			Integer y;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV2: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <33>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");
			
			// TestSet Up
			y = 33;
			s1.add(0,y); 
			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		}//End ClearV2

		 // -----------------------------------------------------------------------------------
		 // TrandferFrom
		 // -----------------------------------------------------------------------------------
		 //! replaces self
		 //! clears source
		 //! ensures: self = #source
		 // -----------------------------------------------------------------------------------

		TEST_METHOD(UT03TransferFromV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer y;

			Logger::WriteMessage(L"UT03TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing: s1 = <44> and s2 = <>");;

			// TestSet Up
			y = 44;
			s2.add(0, y);
			// Execute operation: TransferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::IsTrue(x1 == "<44>", L"s1 = <44>");

			// Verify clears parameter mode: clears source
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");
		}

		// -----------------------------------------------------------------------------------
		// operator =
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04AssignmentV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer y;

			Logger::WriteMessage(L"UT04AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <27>");
			Logger::WriteMessage(L"\toutgoing: s1 = <27> and s2 = <27>");
			
			//Test Set Up
			y = 27;
			s2.add(0, y);
			
			// Execute operation: operator =
			s1 = s2;

			// Verify ensures: self = rhs
			toText(s1, x1);
			toText(s2, x2);
			Assert::IsTrue(x1 == x2, L"s1 = s2");

			// Verify restores parameter mode: restores rhs
			toText(s1, x1);
			Assert::IsTrue(x1 == "<27>", L"s1 = <27>");
		} // UT04AssignmentV1

		// -----------------------------------------------------------------------------------
		// add (Integer pos, T& x)
		// -----------------------------------------------------------------------------------
		//! updates self
		//! restores pos
		//! clears x
		//! requires: 0 <= pos <= |self|
		//! ensures: self =
		//! #self[0, pos) * <#x> *
		//! #self[pos, |#self|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT05AddV1)
		{
			IntegerSequence s1;
			Integer i, j, k;
			Text x1;

			Logger::WriteMessage(L"UT05AddV1: s1.add(j,k);");
			Logger::WriteMessage(L"\tincoming: s1 = <15> and j = 0 and k = 25");
			Logger::WriteMessage(L"\toutgoing: s1 = <25, 15> and j = 0 and k = 0");

			//Test Set Up
			i = 15;
			s1.add(0, i);
			k = 25;

			// Execute operation: add
			s1.add(j, k);

			//Verify self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<25,15>", L"s1 = <25,15>");

			//Verify restores pos
			Assert::IsTrue(j == 0, L"j = 0");

			//Verify clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} //endAdd

		// -----------------------------------------------------------------------------------
		// remove (Integer pos, T& x)
		// -----------------------------------------------------------------------------------
		//! updates self
		//! restores pos
		//! replaces x
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1) and..
		//! self = #self[0, pos) * #self[pos+1, |#self|)
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT06RemoveV1)
		{
			IntegerSequence s1;
			Integer j, k;
			Text x1;

			Logger::WriteMessage(L"UT06AddV1: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77> and j = 4 and k = 99");

			//Test Set Up
			j = 99;
			s1.add(0, j);
			j = 77;
			s1.add(0, j);
			j = 55;
			s1.add(0, j);
			j = 33;
			s1.add(0, j);
			j = 11;
			s1.add(0, j);

			j = 4; //pos

			// Execute operation: add
			s1.remove(j, k);

			
			// Verify: restores pos
			Assert::IsTrue(j == 4, L"j = 4");
			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 99, L"k = 99");
			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77>", L"s1 = <11,33,55,77>");
		
		} //endRemove


		// -----------------------------------------------------------------------------------
		// ReplaceEntry (Integer pos, T& x)
		// -----------------------------------------------------------------------------------
		//! updates self, x
		//! restores pos
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1) and
		//! ensures: self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT07ReplaceEntryV1)
		{
			IntegerSequence s1;
			Integer j, k;
			Text x1;
			
			Logger::WriteMessage(L"UT07ReplaceEntryV1: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 2 and k = 8");
			Logger::WriteMessage(L"\toutgoing: s1 =  <11,33,8,77,99> and j = 2 and k = 55");

			// Test set up
			k = 99;
			s1.add(0, k);
			k = 77;
			s1.add(0, k);
			k = 55;
			s1.add(0, k);
			k = 33;
			s1.add(0, k);
			k = 11;
			s1.add(0, k);
			
			j = 2;
			k = 8;

			// Execute operation
			s1.replaceEntry(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,8,77,99>", L"s1 = <11,33,8,77,99>");
			// Verify updates x
			Assert::IsTrue(k == 55, L"k = 55");
			// Verifys restores pos
			Assert::IsTrue(j == 2, L"j = 2");
		}//endReplaceEntry

		// -----------------------------------------------------------------------------------
		// entry (Integer pos)
		// -----------------------------------------------------------------------------------
		//! restores: self, pos
		//! requires: 0 <= pos < |self|
		//! ensures: <entry> = slef[pos, pos+1)
		// -----------------------------------------------------------------------------------
		
		TEST_METHOD(UT08EntryV1)
		{
			IntegerSequence s1;
			Integer j, k;
			Text x1;

			Logger::WriteMessage(L"UT08ReplaceEntryV1: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 2");
			Logger::WriteMessage(L"\toutgoing: s1 =  <11,33,55,77,99> and j = 2");

			// Test set up
			k = 99;
			s1.add(0, k);
			k = 77;
			s1.add(0, k);
			k = 55;
			s1.add(0, k);
			k = 33;
			s1.add(0, k);
			k = 11;
			s1.add(0, k);

			j = 2;

			// entry operation
			s1.entry(j);

			// Verify restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,99>", L"s1 = <11,33,55,77,99>");
			// Verify restores pos
			Assert::IsTrue(j == 2, L"j = 2");
			// Verify ensures: <entry> = slef[pos, pos+1)
			Assert::IsTrue(s1.entry(j) == 55, L"<entry> = 55");
		}//endEntry


		// -----------------------------------------------------------------------------------
		// append (Sequence1& sToApppend);
		// -----------------------------------------------------------------------------------
		//! updates self
		//! clears sToAppend
		//! ensures: self = #self * #sToAppend
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT09appendV1)
		{
			IntegerSequence s1, s2;
			Integer k;
			Text x1, x2;

			Logger::WriteMessage(L"UT09ReplaceEntryV1: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <10> and s2 = <22>");
			Logger::WriteMessage(L"\toutgoing: s1 = s1 = <10,22> and s2 = <>");

			// Test set up
			k = 10;
			s1.add(0, k);
			k = 22;
			s2.add(0, k);

			// append operation
			s1.append(s2);

			// Verify clears sToAppend
			toText(s2, x1);
			Assert::IsTrue(x1 == "<>", L"s2 = <>");
			// Verify ensures: self = #self * #sToAppend
			toText(s1, x2);
			Assert::IsTrue(x2 == "<10,22>", L"s1 = <10,22>");
		} //endAppend


		// -----------------------------------------------------------------------------------
		// void split(Integer pos, Sequence1& receivingS);
		// -----------------------------------------------------------------------------------
		//! updates self
		//! restores pos
		//! replaces receivingS
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) and
		//! ensures: receivingS = #self[pos, |#self|)
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT10SplitV1)
		{
			IntegerSequence s1, s2;
			Integer k, j;
			Text x1, x2;

			Logger::WriteMessage(L"UT10ReplaceEntryV1: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and s2 = <> and j = 2");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33> and s2 = <55,77,99> and j = 2");

			// Test set up
			k = 99;
			s1.add(0, k);
			k = 77;
			s1.add(0, k);
			k = 55;
			s1.add(0, k);
			k = 33;
			s1.add(0, k);
			k = 11;
			s1.add(0, k);

			j = 2;

			// append operation
			s1.split(j, s2);

			// Verify restores pos
			Assert::IsTrue(j == j, L"j = 2");
			// Verify self = #self[0, pos)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33>", L"s1 = <11,33>");
			// Verify receivingS = #self[pos, |#self|)
			toText(s2, x2);
			Assert::IsTrue(x2 == "<55,77,99>", L"s2 = <55,77,99>");
		} //endSplit


		// -----------------------------------------------------------------------------------
		// length
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: length = |self|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11LengthV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer k , length;

			Logger::WriteMessage(L"UT11LengthV1: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99>");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77,99>");

			// Test set up
			k = 99;
			s1.add(0, k);
			k = 77;
			s1.add(0, k);
			k = 55;
			s1.add(0, k);
			k = 33;
			s1.add(0, k);
			k = 11;
			s1.add(0, k);

			// Verify ensures: length = |self|
			Assert::IsTrue(s1.length() == 5, L"|s1| = 5");
			
			// Verify restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,99>", L"s1 = <11,33,55,77,99>");
			// Verify length = |self|
			Assert::IsTrue(s1.length() == 5, L"|s1| = 5");
		} //endLength
		
	};
}