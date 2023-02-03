# blurhash-server

Scroll down for Englist version of README.

**blurhash-server** 是一个使用 [facil.io](https://facil.io) 构建的 [blurhash](https://github.com/woltapp/blurhash) HTTP服务器。
该项目支持*容器化(containerlize)*，且容器大小不到 10MB 。

[blurhash](https://github.com/woltapp/blurhash) 是一个用于将图片转化成 blurhash string 的工具。
blurhash string 是一个可被存储在数据库中的字符串，也可以被转化成原图被模糊(blur)后的图像。
多用于应用程序需要精美图像，但不得不等待资源服务器响应时，作为图像占位符使用。更多详情可关注 [blurha.sh](https://blurha.sh/)。

<img src="https://raw.githubusercontent.com/woltapp/blurhash/master/Media/WhyBlurHash.png" width="600"/>

## 编译依赖

- [Meson](https://mesonbuild.com): 一个很优秀的high-level编译系统
- [Make](https://www.gnu.org/software/make/): GNU Make
- [Ninja](https://ninja-build.org/): 一个小且关注速度的编译系统

### 可选依赖

- [Docker](https://docker.com): 容器系统，用于容器化(containerlize)

## 使用

**克隆仓库并进入**

```bash
git clone https://github.com/zaiic/blurhash-server.git
cd blurhash-server
```

**直接运行**

```bash
make run
```

**仅编译**

```bash
make build # 可执行文件在build目录中
```

**容器化**

```bash
sudo make containerlize # Docker容器化需要root权限
```

## 示例

```bash
git clone https://github.com/zaiic/blurhash-server.git
cd blurhash-server
make run
```

在另一个终端中:

```bash
curl -sS -F 'data=@/home/zaiic/Pictures/Wallpapers/night.png' http://localhost:3000/blurhash
```
返回json数据: 
```json
{"blurhash":"TP9a%;abNEEGj^t9R1WUbc%5j=W9"}
```

# blurhash-server

**blurhash-server** is a [blurhash](https://github.com/woltapp/blurhash) HTTP Server built by [facil.io](https://facil.io).
And it support containerlization, and its size is less than 10MB.

[blurhash](https://github.com/woltapp/blurhash) is a tool to convert an image file into blurhash string.
blurhash string could be stored in the database and could be converted back to a blurred image.
Usually, it is used as an image placeholder when the application needs exquisite images but has to wait for the response from the resource server.
Learn more [blurha.sh](https://blurha.sh/).

<img src="https://raw.githubusercontent.com/woltapp/blurhash/master/Media/WhyBlurHash.png" width="600"/>


## Compiling Dependencies

- [Meson](https://mesonbuild.com): An awesome high-level build system
- [Make](https://www.gnu.org/software/make/): GNU Make
- [Ninja](https://ninja-build.org/): Ninja is a small build system with a focus on speed

### Optional Dependency

- [Docker](https://docker.com): A container system using for containerlization

## Usage

**Clone The Repository and Change Directory**

```bash
git clone https://github.com/zaiic/blurhash-server.git
cd blurhash-server
```

**Directly Run**

```bash
make run
```

**Only Compile**

```bash
make build # the executable is in the folder build.
```

**Containerlize**

```bash
sudo make containerlize # Docker needs root privilege for containerlization
```

## Example

```bash
git clone https://github.com/zaiic/blurhash-server.git
cd blurhash-server
make run
```

In another terminal:

```bash
curl -sS -F 'data=@/home/zaiic/Pictures/Wallpapers/night.png' http://localhost:3000/blurhash
```
Returned json data: 
```json
{"blurhash":"TP9a%;abNEEGj^t9R1WUbc%5j=W9"}
```
