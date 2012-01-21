varying vec3 vNormal;
uniform float4x4 mMVP;
uniform float4x4 mModelView;
void main()
{
	//normal
	vNormal = (mModelView * vec4(gl_Normal,0.0)).xyz;
	gl_Position = mMVP * gl_Vertex;
}