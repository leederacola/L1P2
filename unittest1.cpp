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

		TEST_METHOD(UT01ClearV1)
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
		
		TEST_METHOD(UT01ClearV2)
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

		TEST_METHOD(UT01TransferFromV1)
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




	};
}