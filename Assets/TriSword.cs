using Microsoft.Xna.Framework;
using Terraria;
using Terraria.ID;
using Terraria.ModLoader;
using System; //Need to create chance.
using System.Threading.Tasks; //Need for countdown timers (not in this weapon).

namespace Test.Items.Weapons
{
	public class TriSword : ModItem
	{
        public override void SetDefaults()
		{
			item.name = "TriSword";		//The name of your weapon
			item.damage = 80;			//The damage of your weapon
			item.melee = true;			//Is your weapon a melee weapon?
			item.width = 40;			//Weapon's texture's width
			item.height = 40;			//Weapon's texture's height
			item.toolTip = "Three swords bound together for imense power.";
			item.toolTip2 = "Has a chance to inflict the On Fire, Frostburn, or Cursed Inferno debuff, or nothing at all.";	//The text showed below your weapon's name
			item.useTime = 15;			//The time span of using the weapon. Remember in terraria, 60 frames is a second.
			item.useAnimation = 15;			//The time span of the using animation of the weapon, suggest set it the same as useTime.
			item.useStyle = 1;			//The use style of weapon, 1 for swinging, 2 for drinking, 3 act like shortsword, 4 for use like life crystal, 5 for use staffs or guns
			item.knockBack = 10;			//The force of knockback of the weapon. Maxium is 20
			item.value = 10000;			//The value of the weapon
			item.rare = 6;				//The rarity of the weapon, from -1 to 13
			item.UseSound = SoundID.Item1;		//The sound when the weapon is using
			item.autoReuse = true;			//Whether the weapon can use automaticly by pressing mousebutton
		}

		/*public override void AddRecipes()
		{
			ModRecipe recipe = new ModRecipe(mod);
			recipe.AddIngredient(ItemID.DirtBlock, 1);
			recipe.SetResult(this);
			recipe.AddRecipe();
		}*/
        
		public async override void OnHitNPC(Player player, NPC target, int damage, float knockback, bool crit) //Note: use asynce to be able to create chance.
		{
            Random r = new Random(); //Create chance.
            int rand = r.Next(1, 100); //Choose random number 1-100

            if (rand < 26)
            {
                target.AddBuff(BuffID.Frostburn, 120);
            }
            
            if (rand > 75)
            {
                target.AddBuff(BuffID.OnFire, 120);
            }

			if (rand > 25 && rand < 50)
            {
                target.AddBuff(BuffID.CursedInferno, 120);
            }
		}

        public override void AddRecipes()
        {
          	ModRecipe recipe = new ModRecipe(mod);
            recipe.AddIngredient(null, "CursedBlade", 1);
            recipe.AddIngredient(null, "FlameSlash", 1);
            recipe.AddIngredient(null, "Icicle", 1);
            recipe.AddIngredient(ItemID.HallowedBar, 10);
           // recipe.AddTile(TileID.Hellforge);
            recipe.SetResult(this);
            recipe.AddRecipe();

			ModRecipe testrecipe = new ModRecipe(mod); //For testing
            testrecipe.AddIngredient(ItemID.DirtBlock, 1);
            testrecipe.SetResult(this);
            testrecipe.AddRecipe();
        }
    }
}