# To Build
<p>This program has been written for GNU/Linux systems. It needs libglfw3, libgl, libglew and stb_image to compile.</p>
<p>When compiled it will output an executable called pai.</p>
<p>To build the program first clone the source code using:</p>
<code>git clone 'https://github.com/Claracinus0Manaricanus/glpai.git'</code>
<p>And enter the directory glpai.   <code>cd glpai</code></p>
<p>In the directory glpai you need to create the cmake files with</p>
<code>cmake .</code>
<p>and run</p>
<code>cmake --build .</code>
<p>to complete.</p>

# Usage
<p>By default the program will compile a demo scene. To write your own scenes use the <b>main.cpp</b> file.
The tools directory has the files needed for fundamental classes such as GameObject and SceneManager. For detailed information read the documents(WIP) <b>Document.odt</b>.
The directory <b>objects</b> is where the .obj files are stored(The program currently only supports .obj files). <b>images</b> are where the needed image files are.
<b>shaders</b> is where shader files for opengl are found. You can edit the files here or write your own shaders to put into SceneManager along with custom shader programs.</p>
