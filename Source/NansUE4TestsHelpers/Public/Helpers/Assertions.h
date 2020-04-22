#pragma once

#include "CoreMinimal.h"
#include "Core\Public\Misc\AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#define TEST_TEXT_FN_DETAILS(Format, ...) \
	FString::Printf(TEXT("%s - %d: %s"), TEXT(__FILE__), __LINE__, *FString::Printf(TEXT(Format), ##__VA_ARGS__))
#define TEST_LOG(text, expression, expected) SpecHelpers::log(text, TEXT(#expression), #expected);

#define TEST_EQ(text, expression, expected)                       \
	if (SpecHelpers::TestEqual(text, expression, expected, this)) \
	{                                                             \
		TEST_LOG(text, expression, expected);                     \
	}
#define TEST_NE(text, expression, expected)                          \
	if (SpecHelpers::TestNotEqual(text, expression, expected, this)) \
	{                                                                \
		TEST_LOG(text, expression, expected);                        \
	}

#define TEST_TRUE(text, expression)                    \
	if (SpecHelpers::TestTrue(text, expression, this)) \
	{                                                  \
		TEST_LOG(text, expression, TEXT("true"));      \
	}

#define TEST_FALSE(text, expression)                    \
	if (SpecHelpers::TestFalse(text, expression, this)) \
	{                                                   \
		TEST_LOG(text, expression, TEXT("false"));      \
	}

#define TEST_NOT_NULL(text, expression)                   \
	if (SpecHelpers::TestNotNull(text, expression, this)) \
	{                                                     \
		TEST_LOG(text, expression, TEXT("not nullptr"));  \
	}

#define TEST_THROW(expression, expectedType)                                                                                  \
	{                                                                                                                         \
		bool caught_expected = false;                                                                                         \
		try                                                                                                                   \
		{                                                                                                                     \
			expression;                                                                                                       \
		}                                                                                                                     \
		catch (expectedType)                                                                                                  \
		{                                                                                                                     \
			caught_expected = true;                                                                                           \
		}                                                                                                                     \
		catch (...)                                                                                                           \
		{                                                                                                                     \
			caught_expected = false;                                                                                          \
			UE_LOG(LogTemp,                                                                                                   \
				Display,                                                                                                      \
				TEXT("Wrong Exception type for " #expression " expression, should Trigger an error of type " #expectedType)); \
		}                                                                                                                     \
		FString Message = TEXT("Expression " #expression " should trigger an exception of type: " #expectedType);             \
		if (SpecHelpers::TestTrue(Message, caught_expected, this))                                                            \
		{                                                                                                                     \
			TEST_LOG(Message, expression, TEXT("true"));                                                                      \
		}                                                                                                                     \
	}

namespace SpecHelpers
{
	template <typename T1>
	inline bool TestTrue(const FString& Description, T1 Expression, FAutomationTestBase* This)
	{
		This->TestTrue(Description, Expression);
		return Expression == true;
	}
	template <typename T1>
	inline bool TestFalse(const FString& Description, T1 Expression, FAutomationTestBase* This)
	{
		This->TestFalse(Description, Expression);
		return Expression == false;
	}
	template <typename T1, typename T2>
	inline bool TestEqual(const FString& Description, T1 Expression, T2 Expected, FAutomationTestBase* This)
	{
		This->TestEqual(Description, Expression, Expected);
		return Expression == Expected;
	}

	template <typename T1, typename T2>
	inline bool TestNotEqual(const FString& Description, T1 Expression, T2 Expected, FAutomationTestBase* This)
	{
		This->TestNotEqual(Description, Expression, Expected);
		return Expression != Expected;
	}

	template <typename T>
	inline bool TestNull(const FString& Description, T Expression, FAutomationTestBase* This)
	{
		This->TestNull(Description, Expression);
		return Expression == nullptr;
	}

	template <typename T>
	inline bool TestNotNull(const FString& Description, T Expression, FAutomationTestBase* This)
	{
		This->TestNotNull(Description, Expression);
		return Expression != nullptr;
	}

	inline void log(const FString& Description, const FString& Expression, const FString& Expected)
	{
		UE_LOG(LogTemp,
			Display,
			TEXT("Test succeed: \"%s\" with expression \"%s\" which expects \"%s\""),
			*Description,
			*Expression,
			*Expected);
	}

	inline bool WaitUntilTrue(const TFunction<bool()>& Pred, const TFunction<bool()>& TestResult, double TimeoutSeconds)
	{
		const double TimeoutEnd = FPlatformTime::Seconds() + TimeoutSeconds;
		while (!Pred() && FPlatformTime::Seconds() < TimeoutEnd)
		{
			FPlatformProcess::Sleep(0);
		}
		return TestResult();
	}
}	 // namespace SpecHelpers

#endif	  // WITH_DEV_AUTOMATION_TESTS