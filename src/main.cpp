#include <NumCpp.hpp>

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

#include <catch2/catch.hpp>

#include <iostream>

namespace {
template <typename T> void mark_unread(const T var) { (void)var; }
} // namespace

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv) {
  // Containers
  [[maybe_unused]] nc::NdArray<int> a0 = {{1, 2}, {3, 4}};
  mark_unread(a0);
  [[maybe_unused]] nc::NdArray<int> a1 = {{1, 2}, {3, 4}, {5, 6}};
  a1.reshape(2, 3);
  [[maybe_unused]] auto a2 = a1.astype<double>();
  mark_unread(a2);

  // // Initializers
  auto a3 = nc::linspace<int>(1, 10, 5);
  auto a4 = nc::arange<int>(3, 7);
  auto a5 = nc::eye<int>(4);
  auto a6 = nc::zeros<int>(3, 4);
  auto a7 = nc::NdArray<int>(3, 4) = 0;
  auto a8 = nc::ones<int>(3, 4);
  auto a9 = nc::NdArray<int>(3, 4) = 1;
  auto a10 = nc::nans(3, 4);
  auto a11 = nc::NdArray<double>(3, 4) = nc::constants::nan;
  auto a12 = nc::empty<int>(3, 4);
  auto a13 = nc::NdArray<int>(3, 4);
  mark_unread(a3);
  mark_unread(a4);
  mark_unread(a5);
  mark_unread(a6);
  mark_unread(a7);
  mark_unread(a8);
  mark_unread(a9);
  mark_unread(a10);
  mark_unread(a11);
  mark_unread(a12);
  mark_unread(a13);

  // Slicing/Broadcasting
  auto a14 = nc::random::randInt<int>({10, 10}, 0, 100);
  auto value = a14(2, 3);
  auto slice = a14({2, 5}, {2, 5});
  auto rowSlice = a14(a14.rSlice(), 7);
  auto values = a14[a14 > 50];
  a14.putMask(a14 > 50, 666);
  mark_unread(value);
  mark_unread(slice);
  mark_unread(rowSlice);
  mark_unread(values);

  // random
  nc::random::seed(666);
  auto a15 = nc::random::randN<double>({3, 4});
  auto a16 = nc::random::randInt<int>({3, 4}, 0, 10);
  auto a17 = nc::random::rand<double>({3, 4});
  auto a18 = nc::random::choice(a17, 3);
  mark_unread(a15);
  mark_unread(a16);
  mark_unread(a17);
  mark_unread(a18);

  // Concatenation
  auto a = nc::random::randInt<int>({3, 4}, 0, 10);
  auto b = nc::random::randInt<int>({3, 4}, 0, 10);
  auto c = nc::random::randInt<int>({3, 4}, 0, 10);
  auto a19 = nc::stack({a, b, c}, nc::Axis::ROW);
  auto a20 = nc::vstack({a, b, c});
  auto a21 = nc::hstack({a, b, c});
  auto a22 = nc::append(a, b, nc::Axis::COL);
  mark_unread(a19);
  mark_unread(a20);
  mark_unread(a21);
  mark_unread(a22);

  // Diagonal, Traingular, and Flip
  auto d = nc::random::randInt<int>({5, 5}, 0, 10);
  auto a23 = nc::diagonal(d);
  auto a24 = nc::triu(a);
  auto a25 = nc::tril(a);
  auto a26 = nc::flip(d, nc::Axis::ROW);
  auto a27 = nc::flipud(d);
  auto a28 = nc::fliplr(d);
  mark_unread(a23);
  mark_unread(a24);
  mark_unread(a25);
  mark_unread(a26);
  mark_unread(a27);
  mark_unread(a28);

  // iteration
  for (auto it = a.cbegin(); it < a.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  for (const auto &arrayValue : a) {
    std::cout << arrayValue << " ";
  }
  std::cout << std::endl;

  // Logical
  auto a29 = nc::where(a > 5, a, b);
  auto a30 = nc::any(a);
  auto a31 = nc::all(a);
  auto a32 = nc::logical_and(a, b);
  auto a33 = nc::logical_or(a, b);
  auto a34 = nc::isclose(a, b);
  auto a35 = nc::allclose(a, b);
  mark_unread(a29);
  mark_unread(a30);
  mark_unread(a31);
  mark_unread(a32);
  mark_unread(a33);
  mark_unread(a34);
  mark_unread(a35);

  // Comparisons
  auto a36 = nc::equal(a, b);
  auto a37 = a == b;
  auto a38 = nc::not_equal(a, b);
  auto a39 = a != b;
  auto [rows, cols] = nc::nonzero(a);
  mark_unread(a36);
  mark_unread(a37);
  mark_unread(a38);
  mark_unread(a39);
  mark_unread(rows);
  mark_unread(cols);

  // Minimum, Maximum, Sorting
  auto value1 = nc::min(a);
  auto value2 = nc::max(a);
  auto value3 = nc::argmin(a);
  auto value4 = nc::argmax(a);
  auto a41 = nc::sort(a, nc::Axis::ROW);
  auto a42 = nc::argsort(a, nc::Axis::COL);
  auto a43 = nc::unique(a);
  auto a44 = nc::setdiff1d(a, b);
  auto a45 = nc::diff(a);
  mark_unread(value1);
  mark_unread(value2);
  mark_unread(value3);
  mark_unread(value4);
  mark_unread(a41);
  mark_unread(a42);
  mark_unread(a43);
  mark_unread(a44);
  mark_unread(a45);

  // Reducers
  auto value5 = nc::sum<int>(a);
  auto a46 = nc::sum<int>(a, nc::Axis::ROW);
  auto value6 = nc::prod<int>(a);
  auto a47 = nc::prod<int>(a, nc::Axis::ROW);
  auto value7 = nc::mean(a);
  auto a48 = nc::mean(a, nc::Axis::ROW);
  auto value8 = nc::count_nonzero(a);
  auto a49 = nc::count_nonzero(a, nc::Axis::ROW);
  mark_unread(value5);
  mark_unread(value6);
  mark_unread(value7);
  mark_unread(value8);
  mark_unread(a46);
  mark_unread(a47);
  mark_unread(a48);
  mark_unread(a49);

  // I/O
  a.print();
  std::cout << a << std::endl;
  // auto tempDir = boost::filesystem::temp_directory_path();
  // auto tempTxt = (tempDir / "temp.txt").string();
  // a.tofile(tempTxt, "\n");
  // auto a50 = nc::fromfile<int>(tempTxt, "\n");
  // auto tempBin = (tempDir / "temp.bin").string();
  // nc::dump(a, tempBin);
  // auto a51 = nc::load<int>(tempBin);

  // Mathematical Functions

  // Basic Functions
  auto a52 = nc::abs(a);
  auto a53 = nc::sign(a);
  auto a54 = nc::remainder(a, b);
  auto a55 = nc::clip(a, 3, 8);
  auto xp = nc::linspace<double>(0.0, 2.0 * nc::constants::pi, 100);
  auto fp = nc::sin(xp);
  auto x = nc::linspace<double>(0.0, 2.0 * nc::constants::pi, 1000);
  auto f = nc::interp(x, xp, fp);
  mark_unread(a52);
  mark_unread(a53);
  mark_unread(a54);
  mark_unread(a55);
  mark_unread(f);

  // Exponential Functions
  auto a56 = nc::exp(a);
  auto a57 = nc::expm1(a);
  auto a58 = nc::log(a);
  auto a59 = nc::log1p(a);
  mark_unread(a56);
  mark_unread(a57);
  mark_unread(a58);
  mark_unread(a59);

  // Power Functions
  auto a60 = nc::power<int>(a, 4);
  auto a61 = nc::sqrt(a);
  auto a62 = nc::square(a);
  auto a63 = nc::cbrt(a);
  mark_unread(a60);
  mark_unread(a61);
  mark_unread(a62);
  mark_unread(a63);

  // Trigonometric Functions
  auto a64 = nc::sin(a);
  auto a65 = nc::cos(a);
  auto a66 = nc::tan(a);
  mark_unread(a64);
  mark_unread(a65);
  mark_unread(a66);

  // Hyperbolic Functions
  auto a67 = nc::sinh(a);
  auto a68 = nc::cosh(a);
  auto a69 = nc::tanh(a);
  mark_unread(a67);
  mark_unread(a68);
  mark_unread(a69);

  // Classification Functions
  auto a70 = nc::isnan(a.astype<double>());
  mark_unread(a70);

  // Linear Algebra
  auto a71 = nc::norm<int>(a);
  auto a72 = nc::dot<int>(a, b.transpose());
  auto a73 = nc::random::randInt<int>({3, 3}, 0, 10);
  auto a74 = nc::random::randInt<int>({4, 3}, 0, 10);
  auto a75 = nc::random::randInt<int>({1, 4}, 0, 10);
  auto value9 = nc::linalg::det(a73);
  mark_unread(a71);
  mark_unread(a72);
  mark_unread(a73);
  mark_unread(a74);
  mark_unread(a75);
  mark_unread(value9);

  auto a76 = nc::linalg::inv(a73);
  auto a77 = nc::linalg::lstsq(a74, a75);
  auto a78 = nc::linalg::matrix_power<int>(a73, 3);
  auto a79 = nc::linalg::multi_dot<int>({a, b.transpose(), c});
  nc::NdArray<double> u;
  nc::NdArray<double> s;
  nc::NdArray<double> vt;
  nc::linalg::svd(a.astype<double>(), u, s, vt);
  mark_unread(a76);
  mark_unread(a77);
  mark_unread(a78);
  mark_unread(a79);
  mark_unread(u);
  mark_unread(s);
  mark_unread(vt);

  std::cout << "Hello World! yay\n";
  return 0;
}
