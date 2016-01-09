#ifndef TEST_FIXEDPOINT
#define TEST_FIXEDPOINT

#include <iostream>

#include "bandit/bandit.h"
#include "Fixed.hpp"
using namespace bandit;

go_bandit([]() {
	describe("FixedPoint Tests", [&]() {
		describe("Q15.16", [&]() {
			it("set value", [&]() {
				Q<int32_t, 16> q1 = 1.5;
				float result = q1.to_float();
				float expected = 1.5;
				AssertThat(result, Equals(expected));
			});

			it("equals", [&]() {
				Q<int32_t, 16> q1 = 10.5;
				Q<int32_t, 16> q2 = 10.5;
				bool result = (q1 == q2);
				AssertThat(result, Equals(true));
			});

			it("add", [&]() {
				Q<int32_t, 16> q1 = 2;
				Q<int32_t, 16> q2 = 3;
				Q<int32_t, 16> result = q1+q2;
				Q<int32_t, 16> expected = 5;
				bool answer = (result == expected);
				AssertThat(answer, Equals(true));

				q1 = 1.5;
				result = q1 + q2;
				expected = 4.5;
				answer = (result == expected);
				AssertThat(answer, Equals(true));
			});

			it("subtract", [&]() {
				Q<int32_t, 16> q1 = 10;
				Q<int32_t, 16> q2 = 3.5;
				Q<int32_t, 16> result = q1-q2;
				Q<int32_t, 16> expected = 6.5;
				bool answer = (result == expected);
				AssertThat(answer, Equals(true));
			});
		});

		describe("UQ16.16", [&]() {
			it("set value", [&]() {
				Q<uint32_t, 16> q1 = 1.5;
				float result = q1.to_float();
				float expected = 1.5;
				AssertThat(result, Equals(expected));
			});

			it("equals", [&]() {
				Q<uint32_t, 16> q1 = 10.5;
				Q<uint32_t, 16> q2 = 10.5;
				bool result = (q1 == q2);
				AssertThat(result, Equals(true));
			});

			it("add", [&]() {
				Q<uint32_t, 16> q1 = 2;
				Q<uint32_t, 16> q2 = 3;
				Q<uint32_t, 16> result = q1+q2;
				Q<uint32_t, 16> expected = 5;
				bool answer = result == expected;
				AssertThat(answer, Equals(true));
			});
		});
	});
});

#endif