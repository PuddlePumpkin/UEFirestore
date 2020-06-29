// Some copyright should be here...

using UnrealBuildTool;
using System.IO;
public class FireStore : ModuleRules
{
	private string jwt
	{
		get { return Path.Combine(ModuleDirectory, "external"); }
	}
	public FireStore(ReadOnlyTargetRules Target) : base(Target)
	{
	PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			PublicSystemIncludePaths.AddRange(
			new string[]
            {
                jwt
            }
            );
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"OpenSSL",
				// ... add private dependencies that you statically link with here ...
				//json Http stuff	
				"Http",
				"Json",
				"JsonUtilities",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
